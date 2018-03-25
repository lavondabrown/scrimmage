/*!
 * @file
 *
 * @section LICENSE
 *
 * Copyright (C) 2017 by the Georgia Tech Research Institute (GTRI)
 *
 * This file is part of SCRIMMAGE.
 *
 *   SCRIMMAGE is free software: you can redistribute it and/or modify it under
 *   the terms of the GNU Lesser General Public License as published by the
 *   Free Software Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *
 *   SCRIMMAGE is distributed in the hope that it will be useful, but WITHOUT
 *   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 *   License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public License
 *   along with SCRIMMAGE.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @author Kevin DeMarco <kevin.demarco@gtri.gatech.edu>
 * @author Eric Squires <eric.squires@gtri.gatech.edu>
 * @date 31 July 2017
 * @version 0.1.0
 * @brief Brief file description.
 * @section DESCRIPTION
 * A Long description goes here.
 *
 */

#include <grpc++/grpc++.h>

#include <scrimmage/plugin_manager/RegisterPlugin.h>
#include <scrimmage/plugins/autonomy/ExternalControl/ExternalControl.h>
#include <scrimmage/plugins/autonomy/ExternalControl/ExternalControlClient.h>
#include <scrimmage/plugins/interaction/ExternalControlInteraction/ExternalControlInteraction.h>
#include <scrimmage/entity/Entity.h>
#include <scrimmage/common/Utilities.h>
#include <scrimmage/math/State.h>

#include <memory>
#include <limits>
#include <iostream>

#include <boost/optional.hpp>

namespace sc = scrimmage;
namespace sp = scrimmage_proto;

REGISTER_PLUGIN(scrimmage::EntityInteraction,
                scrimmage::interaction::ExternalControlInteraction,
                ExternalControlInteraction_plugin)

namespace scrimmage {
namespace interaction {

bool ExternalControlInteraction::init(std::map<std::string, std::string> &mission_params,
                                      std::map<std::string, std::string> &plugin_params) {
    std::string server_address = plugin_params.at("server_address");
    external_control_client_ = std::make_shared<autonomy::ExternalControlClient>();
    *external_control_client_ =
        autonomy::ExternalControlClient(grpc::CreateChannel(
            server_address, grpc::InsecureChannelCredentials()));
    return true;
}


bool ExternalControlInteraction::step_entity_interaction(std::list<sc::EntityPtr> &ents,
                                                  double t, double dt) {
    if (ents.empty()) return true;

    if (ext_ctrl_vec_.empty()) {
        for (auto &e : ents) {
            for (auto &a : e->autonomies()) {
                auto p = std::dynamic_pointer_cast<autonomy::ExternalControl>(a);
                if (p) {
                    ext_ctrl_vec_.push_back(p);
                }
            }
        }
    }

    if (ext_ctrl_vec_.empty()) return true;

    // receive action from grpc, send action to each autonomy, get reward/obs
    if (!env_sent_) {
        if (!send_env()) {
            return false;
        }
        env_sent_ = true;
    }

    // get reward/obs/done
    // terminate is supposed to occur after the first state is experienced
    auto actions = send_action_result(t, dt, false, t != 0);
    if (!actions || actions->done()) return false;

    // receive action
    handle_action(*actions);
    return true;
}

void ExternalControlInteraction::handle_action(scrimmage_proto::Actions &actions) {
    for (int i = 0; i < actions.actions_size(); i++) {
        ext_ctrl_vec_[i]->set_action(actions.actions(i));
    }
}

boost::optional<scrimmage_proto::Actions>
ExternalControlInteraction::send_action_result(double t, double dt, bool done, bool allow_done) {
    sp::ActionResults action_results;

    for (auto &a : ext_ctrl_vec_) {
        double temp_reward;
        bool temp_done;
        std::tie(temp_done, temp_reward) = a->calc_reward(t, dt);
        sp::ActionResult *ar = action_results.add_action_results();
        *ar = a->get_observation(t);
        ar->set_done(allow_done ? (done || temp_done) : false);
        ar->set_reward(allow_done ? temp_reward : 0);
    }

    return external_control_client_->send_action_results(action_results);
}

bool ExternalControlInteraction::send_env() {
    sp::Environments envs;
    for (auto &a : ext_ctrl_vec_) {
        *envs.add_envs() = a->get_env();
    }

    return external_control_client_->send_environments(envs);
}

void ExternalControlInteraction::close(double t) {
    send_action_result(t, 0, true, true);
}

} // namespace interaction
} // namespace scrimmage
