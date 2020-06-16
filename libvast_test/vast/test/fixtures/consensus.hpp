/******************************************************************************
 *                    _   _____   __________                                  *
 *                   | | / / _ | / __/_  __/     Visibility                   *
 *                   | |/ / __ |_\ \  / /          Across                     *
 *                   |___/_/ |_/___/ /_/       Space and Time                 *
 *                                                                            *
 * This file is part of VAST. It is subject to the license terms in the       *
 * LICENSE file found in the top-level directory of this distribution and at  *
 * http://vast.io/license. No part of VAST, including this file, may be       *
 * copied, modified, propagated, or distributed except according to the terms *
 * contained in the LICENSE file.                                             *
 ******************************************************************************/

#pragma once

#include "vast/test/fixtures/actor_system.hpp"

#include "vast/fwd.hpp"
#include "vast/system/raft.hpp"

namespace fixtures {

struct consensus : actor_system {
  consensus() {
    launch();
  }

  ~consensus() {
    shutdown();
  }

  void launch() {
    using namespace vast;
    using namespace vast::system;
    server1 = self->spawn(raft::consensus, directory / "server1");
    server2 = self->spawn(raft::consensus, directory / "server2");
    server3 = self->spawn(raft::consensus, directory / "server3");
    self->send(server1, atom::id::value, raft::server_id{1});
    self->send(server2, atom::id::value, raft::server_id{2});
    self->send(server3, atom::id::value, raft::server_id{3});
    // Make it deterministic.
    self->send(server1, atom::seed::value, uint64_t{42});
    self->send(server2, atom::seed::value, uint64_t{43});
    self->send(server3, atom::seed::value, uint64_t{44});
    // Setup peers.
    self->send(server1, atom::peer::value, server2, raft::server_id{2});
    self->send(server1, atom::peer::value, server3, raft::server_id{3});
    self->send(server2, atom::peer::value, server1, raft::server_id{1});
    self->send(server2, atom::peer::value, server3, raft::server_id{3});
    self->send(server3, atom::peer::value, server1, raft::server_id{1});
    self->send(server3, atom::peer::value, server2, raft::server_id{2});
    self->send(server1, atom::run::value);
    self->send(server2, atom::run::value);
    self->send(server3, atom::run::value);
    self->send(server1, atom::subscribe::value, self);
    self->send(server2, atom::subscribe::value, self);
    self->send(server3, atom::subscribe::value, self);
    MESSAGE("sleeping until leader got elected");
    std::this_thread::sleep_for(raft::election_timeout * 2);
  }

  void shutdown() {
    using namespace caf;
    using namespace vast::system;
    self->send_exit(server1, exit_reason::user_shutdown);
    self->wait_for(server1);
    self->send_exit(server2, exit_reason::user_shutdown);
    self->wait_for(server2);
    self->send_exit(server3, exit_reason::user_shutdown);
    self->wait_for(server3);
  }

  template <class... Ts>
  auto replicate(const caf::actor& server, Ts&&... xs) {
    using namespace vast;
    using namespace vast::system;
    auto command = caf::make_message(std::forward<Ts>(xs)...);
    self->request(server, consensus_timeout, atom::replicate::value, command)
      .receive([](atom::ok) { /* nop */ }, error_handler());
  }

  template <class... Ts>
  caf::message await(vast::system::raft::index_type index) {
    caf::message result;
    auto n = 0;
    self->receive_for(n, 3) (
      [&](vast::system::raft::index_type i, const caf::message& msg) {
        REQUIRE_EQUAL(i, index);
        result = msg;
      },
      error_handler()
    );
    return result;
  }

  caf::actor server1;
  caf::actor server2;
  caf::actor server3;
};

} // namespace fixtures

