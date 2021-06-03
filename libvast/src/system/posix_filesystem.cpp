//    _   _____   __________
//   | | / / _ | / __/_  __/     Visibility
//   | |/ / __ |_\ \  / /          Across
//   |___/_/ |_/___/ /_/       Space and Time
//
// SPDX-FileCopyrightText: (c) 2020 The VAST Contributors
// SPDX-License-Identifier: BSD-3-Clause

#include "vast/system/posix_filesystem.hpp"

#include "vast/chunk.hpp"
#include "vast/detail/assert.hpp"
#include "vast/io/read.hpp"
#include "vast/io/save.hpp"
#include "vast/logger.hpp"
#include "vast/system/status_verbosity.hpp"

#include <caf/config_value.hpp>
#include <caf/dictionary.hpp>
#include <caf/result.hpp>
#include <caf/settings.hpp>

#include <filesystem>

namespace vast::system {

filesystem_actor::behavior_type
posix_filesystem(filesystem_actor::stateful_pointer<posix_filesystem_state> self,
                 const std::filesystem::path& root) {
  self->state.root = root;
  return {
    [self](atom::write, const std::filesystem::path& filename,
           chunk_ptr chk) -> caf::result<atom::ok> {
      VAST_ASSERT(chk != nullptr);
      const auto path
        = filename.is_absolute() ? filename : self->state.root / filename;
      if (filename.is_absolute())
        VAST_WARN("{} received request to write to absolute path {}; this is "
                  "deprecated and will be disabled in the future",
                  self, filename);
      if (auto err = io::save(path, as_bytes(chk))) {
        ++self->state.stats.writes.failed;
        return err;
      } else {
        ++self->state.stats.writes.successful;
        ++self->state.stats.writes.bytes += chk->size();
        return atom::ok_v;
      }
    },
    [self](atom::read,
           const std::filesystem::path& filename) -> caf::result<chunk_ptr> {
      const auto path
        = filename.is_absolute() ? filename : self->state.root / filename;
      if (filename.is_absolute())
        VAST_WARN("{} received request to read from absolute path {}; this is "
                  "deprecated and will be disabled in the future",
                  self, filename);
      if (auto bytes = io::read(path)) {
        ++self->state.stats.reads.successful;
        ++self->state.stats.reads.bytes += bytes->size();
        return chunk::make(std::move(*bytes));
      } else {
        ++self->state.stats.reads.failed;
        return bytes.error();
      }
    },
    [self](atom::mmap,
           const std::filesystem::path& filename) -> caf::result<chunk_ptr> {
      const auto path
        = filename.is_absolute() ? filename : self->state.root / filename;
      if (filename.is_absolute())
        VAST_WARN("{} received request to mmap absolute path {}; this is "
                  "deprecated and will be disabled in the future",
                  self, filename);
      if (auto chk = chunk::mmap(path)) {
        ++self->state.stats.mmaps.successful;
        ++self->state.stats.mmaps.bytes += chk->get()->size();
        return chk;
      } else {
        ++self->state.stats.mmaps.failed;
        return nullptr;
      }
    },
    [self](atom::status, status_verbosity v) {
      auto result = caf::settings{};
      if (v >= status_verbosity::info)
        caf::put(result, "filesystem.type", "POSIX");
      if (v >= status_verbosity::debug) {
        auto& ops = put_dictionary(result, "filesystem.operations");
        auto add_stats = [&](auto& name, auto& stats) {
          auto& dict = put_dictionary(ops, name);
          caf::put(dict, "successful", stats.successful);
          caf::put(dict, "failed", stats.failed);
          caf::put(dict, "bytes", stats.bytes);
        };
        add_stats("writes", self->state.stats.writes);
        add_stats("reads", self->state.stats.reads);
        add_stats("mmaps", self->state.stats.mmaps);
      }
      return result;
    },
  };
}

} // namespace vast::system
