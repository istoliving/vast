//    _   _____   __________
//   | | / / _ | / __/_  __/     Visibility
//   | |/ / __ |_\ \  / /          Across
//   |___/_/ |_/___/ /_/       Space and Time
//
// SPDX-FileCopyrightText: (c) 2021 The VAST Contributors
// SPDX-License-Identifier: BSD-3-Clause

#include "vast/detail/flat_map.hpp"
#include "vast/fbs/partition.hpp"
#include "vast/span.hpp"
#include "vast/system/actors.hpp"

#include <caf/expected.hpp>

#include <string>

// FIXME: Move header to vast/system directory
namespace vast::system {

// FIXME:
//   * Introduce `store_plugin` type and pass a plugin_ptr to register
//   * Pass the node instead of just the filesystem actor
class store_factory {
public:
  using handler
    = caf::expected<store_actor> (*)(filesystem_actor, span<uint8_t> data);

  /// Registers a new handler to create a store implementation.
  static void register_(const std::string& name, handler);

  /// Spawn a new store actor. The `header` was previously created by
  /// `make_header` above.
  static caf::expected<store_actor>
  get(const std::string& name, filesystem_actor fs, span<uint8_t> header);

  // TODO: With store plugins, we also need some kind of third handler to make
  // the corresponding store header to be put into the partition.

private:
  static detail::flat_map<std::string, handler> handlers_;
};

// Callback handler for the "native" stores currently supported.
caf::expected<store_actor>
  local_store_load_handler(filesystem_actor, vast::span<uint8_t>);

caf::expected<store_actor>
  global_store_load_handler(filesystem_actor, vast::span<uint8_t>);

} // namespace vast::system
