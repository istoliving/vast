//    _   _____   __________
//   | | / / _ | / __/_  __/     Visibility
//   | |/ / __ |_\ \  / /          Across
//   |___/_/ |_/___/ /_/       Space and Time
//
// SPDX-FileCopyrightText: (c) 2020 The VAST Contributors
// SPDX-License-Identifier: BSD-3-Clause

#include "vast/system/spawn_type_registry.hpp"

#include "vast/defaults.hpp"
#include "vast/logger.hpp"
#include "vast/system/node.hpp"
#include "vast/system/spawn_arguments.hpp"
#include "vast/system/type_registry.hpp"

#include <caf/settings.hpp>
#include <caf/typed_event_based_actor.hpp>

namespace vast::system {

caf::expected<caf::actor>
spawn_type_registry(node_actor::stateful_pointer<node_state> self,
                    spawn_arguments& args) {
  if (!args.empty())
    return unexpected_arguments(args);
  // TODO: The TYPE REGISTRY still does not use the FILESYSTEM actor for
  // persisting its state. Until it does we need to prepend the
  // `vast.db-directory` here.
  auto db_dir = std::filesystem::path{caf::get_or(
    args.inv.options, "vast.db-directory", defaults::system::db_directory)};
  auto handle = self->spawn(type_registry, db_dir / args.label);
  self->request(handle, defaults::system::initial_request_timeout, atom::load_v)
    .await([](atom::ok) {},
           [](caf::error& err) {
             VAST_WARN("type-registry failed to load taxonomy "
                       "definitions: {}",
                       render(std::move(err)));
           });
  VAST_VERBOSE("{} spawned the type-registry", self);
  if (auto [accountant] = self->state.registry.find<accountant_actor>();
      accountant)
    self->send(handle, caf::actor_cast<accountant_actor>(accountant));
  return caf::actor_cast<caf::actor>(handle);
}

} // namespace vast::system
