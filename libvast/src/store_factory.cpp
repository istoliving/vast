//    _   _____   __________
//   | | / / _ | / __/_  __/     Visibility
//   | |/ / __ |_\ \  / /          Across
//   |___/_/ |_/___/ /_/       Space and Time
//
// SPDX-FileCopyrightText: (c) 2018 The VAST Contributors
// SPDX-License-Identifier: BSD-3-Clause

#include "vast/store_factory.hpp"

#include "vast/error.hpp"

#include <caf/typed_event_based_actor.hpp>
#include <fmt/format.h>

namespace vast::system {

detail::flat_map<std::string, store_factory::handler> store_factory::handlers_;

void store_factory::register_(const std::string& name, handler handler) {
  handlers_[name] = handler;
}

// chunk_ptr store_factory::make_header(const std::string& name, const uuid&
// partition_id) { }

caf::expected<store_actor>
store_factory::get(const std::string& name, span<uint8_t> header) {
  auto handler = handlers_.find(name);
  if (handler == handlers_.end())
    return caf::make_error(ec::invalid_argument,
                           fmt::format("unknown store '{}'", name));
  return handler->second(header);
}

caf::expected<store_actor>
local_store_load_handler(node_actor node, vast::span<uint8_t>) {
}

caf::expected<store_actor>
global_store_load_handler(node_actor node, vast::span<uint8_t>) {
  caf::scoped_actor self{node.home_system()};
  return get_node_components<class Actors>(caf::scoped_actor & self,
                                           const node_actor& node)
}

} // namespace vast::system
