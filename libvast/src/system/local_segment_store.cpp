//    _   _____   __________
//   | | / / _ | / __/_  __/     Visibility
//   | |/ / __ |_\ \  / /          Across
//   |___/_/ |_/___/ /_/       Space and Time
//
// SPDX-FileCopyrightText: (c) 2021 The VAST Contributors
// SPDX-License-Identifier: BSD-3-Clause

#include "vast/system/local_segment_store.hpp"

#include "vast/detail/overload.hpp"
#include "vast/detail/zip_iterator.hpp"
#include "vast/fbs/partition.hpp"
#include "vast/ids.hpp"
#include "vast/logger.hpp"
#include "vast/query.hpp"
#include "vast/segment_store.hpp"
#include "vast/span.hpp"
#include "vast/table_slice.hpp"

#include <caf/settings.hpp>
#include <fmt/format.h>

#include <vector>

namespace vast::system {

std::filesystem::path store_path_for_partition(const uuid& partition_id) {
  auto store_filename = fmt::format("{}.store", partition_id);
  return std::filesystem::path{"archive"} / store_filename;
}

caf::expected<store_actor>
local_store_handler(filesystem_actor& fs, vast::span<uint8_t> span) {
  const auto* header
    = flatbuffers::GetRoot<fbs::partition::store_header_local::v0>(span.data());
  if (!header)
    return caf::make_error(ec::format_error, "invalid store header");
  const auto* path_str = header->path();
  if (!path_str)
    return caf::make_error(ec::format_error, "no path in header");
  const auto& path = std::filesystem::path{path_str->c_str()};
  caf::scoped_actor self{fs.home_system()};
  return self->spawn(passive_local_store, fs, path);
}

store_actor::behavior_type
passive_local_store(store_actor::stateful_pointer<passive_store_state> self,
                    filesystem_actor fs, const std::filesystem::path& path) {
  // TODO: We probably want 'read' rather than 'mmap' here for
  // predictable performance.
  self->set_exit_handler([self](const caf::exit_msg& msg) {
    for (auto&& [expr, ids, rp] :
         std::exchange(self->state.deferred_requests, {}))
      rp.deliver(caf::make_error(ec::lookup_error, "partition store shutting "
                                                   "down"));
  });
  self->request(fs, caf::infinite, atom::mmap_v, path)
    .then([self](chunk_ptr chunk) {
      // self->state.data = std::move(chunk);
      auto seg = segment::make(std::move(chunk));
      if (!seg) {
        VAST_ERROR("couldnt create segment from chunk: {}", seg.error());
        self->send_exit(self, caf::exit_reason::unhandled_exception);
        return;
      }
      self->state.segment = std::move(*seg);
      // Delegate all deferred evaluations now that we have the partition chunk.
      VAST_DEBUG("{} delegates {} deferred evaluations", self,
                 self->state.deferred_requests.size());
      for (auto&& [expr, ids, rp] :
           std::exchange(self->state.deferred_requests, {}))
        rp.delegate(static_cast<store_actor>(self), std::move(expr),
                    std::move(ids));
    });
  return {
    // store
    [self](query query, ids ids) -> caf::result<atom::done> {
      if (!self->state.segment) {
        auto rp = caf::typed_response_promise<atom::done>();
        self->state.deferred_requests.emplace_back(query, ids, rp);
        return rp;
      }
      auto slices = self->state.segment->lookup(ids);
      if (!slices)
        return slices.error();
      std::vector<expression> checkers;
      for (const auto& slice : *slices) {
        if (query.expr == expression{}) {
          checkers.emplace_back();
        } else {
          auto c = tailor(query.expr, slice.layout());
          if (!c)
            return c.error();
          checkers.emplace_back(prune_meta_predicates(std::move(*c)));
        }
      }
      auto zipped = detail::zip(*slices, checkers);
      caf::visit(detail::overload{
                   [&](const query::count& count) {
                     if (count.mode == query::count::estimate)
                       die("logic error detected");
                     for (size_t i = 0; i < slices->size(); ++i) {
                       const auto& slice = slices->at(i);
                       const auto& checker = checkers.at(i);
                       auto result = count_matching(slice, checker, ids);
                       self->send(count.sink, result);
                     }
                   },
                   [&](const query::extract& extract) {
                     for (const auto& [slice, checker] : zipped) {
                       if (extract.policy == query::extract::preserve_ids) {
                         for (auto& sub_slice : select(slice, ids)) {
                           if (query.expr == expression{}) {
                             self->send(extract.sink, sub_slice);
                           } else {
                             auto hits = evaluate(checker, sub_slice);
                             for (auto& final_slice : select(sub_slice, hits))
                               self->send(extract.sink, final_slice);
                           }
                         }
                       } else {
                         // TODO: Make something like foreach_
                         auto final_slice = filter(slice, checker, ids);
                         if (final_slice)
                           self->send(extract.sink, *final_slice);
                       }
                     }
                   },
                   [&](query::erase) {
                     die("logic error detected");
                   },
                 },
                 query.cmd);
      return atom::done_v;
    },
    [self](atom::erase, ids) -> atom::done {
      // [...]
      return atom::done_v;
    },
  };
}

store_builder_actor::behavior_type active_local_store(
  store_builder_actor::stateful_pointer<active_store_state> self,
  filesystem_actor fs, const std::filesystem::path& path) {
  VAST_INFO("spawning active local store active"); // FIXME: INFO -> DEBUG
  // TODO: The shutdown path is copied from the archive; align it
  // with the fs actor.
  self->state.builder
    = std::make_unique<segment_builder>(defaults::system::max_segment_size);
  self->set_exit_handler([self, path, fs](const caf::exit_msg&) {
    VAST_INFO("exiting active store");
    auto seg = self->state.builder->finish();
    self->request(fs, caf::infinite, atom::write_v, path, seg.chunk())
      .then([](atom::ok) { /* nop */ },
            [self](caf::error& err) {
              VAST_ERROR("failed to flush archive {}", to_string(err));
            });
    self->quit();
  });

  return {
    // store
    [self](query, const ids& ids) -> atom::done {
      auto result = self->state.builder->lookup(ids);
      // TODO: return result
      // ...
      return atom::done_v;
    },
    [self](atom::erase, const ids& ids) -> caf::result<atom::done> {
      // TODO
      // if (auto result = self->state.builder->erase(ids); !result)
      // return result;
      return atom::done_v;
    },
    // store builder
    [self](
      caf::stream<table_slice> in) -> caf::inbound_stream_slot<table_slice> {
      return self
        ->make_sink(
          in, [=](caf::unit_t&) {},
          [=](caf::unit_t&, std::vector<table_slice>& batch) {
            VAST_WARN("local store gets tables lice");
            for (auto& slice : batch)
              if (auto error = self->state.builder->add(slice))
                VAST_ERROR("{} failed to add table slice to store {}", self,
                           render(error));
          },
          [=](caf::unit_t&, const caf::error&) {

          })
        .inbound_slot();
    },
    // Conform to the protocol of the STATUS CLIENT actor.
    [self](atom::status,
           status_verbosity) -> caf::dictionary<caf::config_value> {
      return {};
    },
  };
}

} // namespace vast::system
