//    _   _____   __________
//   | | / / _ | / __/_  __/     Visibility
//   | |/ / __ |_\ \  / /          Across
//   |___/_/ |_/___/ /_/       Space and Time
//
// SPDX-FileCopyrightText: (c) 2021 The VAST Contributors
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include "vast/fwd.hpp"

#include "vast/chunk.hpp"
#include "vast/segment_builder.hpp"
#include "vast/system/actors.hpp"

#include <caf/typed_event_based_actor.hpp>

namespace vast::system {

struct active_store_state {
  std::filesystem::path path;
  std::unique_ptr<vast::segment_builder> builder;
};

struct passive_store_state {
  /// Holds requests that were coming in while the data
  /// was still being loaded from disk.
  using request = std::tuple<vast::query, vast::ids,
                             caf::typed_response_promise<atom::done>>;
  std::vector<request> deferred_requests;

  /// The segment corresponding to this local store.
  caf::optional<vast::segment> segment = {};
};

std::filesystem::path store_path_for_partition(const vast::uuid&);

store_builder_actor::behavior_type
active_local_store(store_builder_actor::stateful_pointer<active_store_state>,
                   filesystem_actor filesystem,
                   const std::filesystem::path& dir);

store_actor::behavior_type
passive_local_store(store_actor::stateful_pointer<passive_store_state>,
                    filesystem_actor filesystem,
                    const std::filesystem::path& path);

} // namespace vast::system
