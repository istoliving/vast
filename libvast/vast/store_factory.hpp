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

#include <string>

namespace vast::system {

class store_factory {
public:
  using handler = store_actor (*)(vast::span data);

  static void register_(const std::string& name, handler);
  static store_actor get(const fbs::partition::store_header::v0& header);

private:
  detail::flat_map<std::string, handler> handlers_;
};

} // namespace vast::system
