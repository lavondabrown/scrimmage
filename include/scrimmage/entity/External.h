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
#ifndef INCLUDE_SCRIMMAGE_ENTITY_EXTERNAL_H_
#define INCLUDE_SCRIMMAGE_ENTITY_EXTERNAL_H_

#include <scrimmage/autonomy/Autonomy.h>
#include <scrimmage/common/RTree.h>
#include <scrimmage/common/DelayedTask.h>
#include <scrimmage/entity/Entity.h>
#include <scrimmage/log/Log.h>
#include <scrimmage/math/State.h>
#include <scrimmage/motion/Controller.h>
#include <scrimmage/proto/ProtoConversions.h>
#include <scrimmage/proto/Shape.pb.h>
#include <scrimmage/pubsub/Subscriber.h>
#include <scrimmage/pubsub/Publisher.h>

#include <algorithm>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <mutex> // NOLINT

#include <iostream>

#include <boost/type_index.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

namespace scrimmage {

class External {
 public:
    External();
    EntityPtr &entity();
    void setup_logging();
    bool create_entity(int max_entities, int entity_id,
                       const std::string &entity_name);

    template <class AcceptFunc>
    bool create_entity(int max_entities, int entity_id,
                       const std::string &entity_name,
                       AcceptFunc accept_func) {

        if (!create_entity(max_entities, entity_id, entity_name)) return false;

        auto filter_func = [&](auto &p) {return !accept_func(p);};
        auto &a = entity_->autonomies();
        a.erase(std::remove_if(a.begin(), a.end(), filter_func), a.end());

        return true;
    }

    bool create_interactions();

    double min_motion_dt = 1;
    VariableIO vars;
    std::mutex mutex;
    DelayedTask update_contacts_task;
    MissionParsePtr mp();
    void send_messages();

 protected:
    void update_ents();
    EntityPtr entity_;
    std::list<EntityInteractionPtr> ent_inters_;
    std::list<MetricsPtr> metrics_;

    PluginManagerPtr plugin_manager_;
    std::shared_ptr<Log> log_;
    double last_t_;
    PubSubPtr pubsub_;
    TimePtr time_;
    MissionParsePtr mp_;

    std::shared_ptr<std::unordered_map<int, int>> id_to_team_map_;
    std::shared_ptr<std::unordered_map<int, EntityPtr>> id_to_ent_map_;
    std::list<EntityPtr> ents_;

 public:
    bool step(double t);
    PubSubPtr pubsub() {
        return pubsub_;
    }

#ifdef ROSCPP_ROS_H

 public:
    template <class ScType, class Sc2Ros>
    void pub_cb(std::string network_name, std::string topic_name,
                Sc2Ros sc2ros, ros::Publisher ros_pub) {

        auto ros_pub_ptr = std::make_shared<ros::Publisher>(ros_pub);

        boost::optional<std::list<NetworkDevicePtr>> pubs =
            pubsub_->find_pubs(network_name, topic_name);

        if (pubs) {
            for (NetworkDevicePtr dev : *pubs) {
                PublisherPtr pub = std::dynamic_pointer_cast<Publisher>(dev);

                pub->callback = [=](MessageBasePtr sc_msg) {
                    auto sc_msg_cast = std::dynamic_pointer_cast<Message<ScType>>(sc_msg);
                    if (sc_msg_cast == nullptr) {
                        std::cout << "could not cast to "
                                  << boost::typeindex::type_id<Message<ScType>>().pretty_name()
                                  << " in pub_cb on topic " << pub->get_topic() << std::endl;
                    } else {
                        ros_pub_ptr->publish(sc2ros(sc_msg_cast->data));
                    }
                };
            }
        } else {
            std::cout << "Failed to setup scrimmage to ROS publisher." << std::endl;
        }
    }

    template <class RosType, class Ros2Sc>
    boost::function<void(const boost::shared_ptr<RosType const>&)>
    sub_cb(std::string network_name, std::string topic_name, Ros2Sc ros2sc) {

        boost::optional<std::list<NetworkDevicePtr>> subs =
            pubsub_->find_subs(network_name, topic_name);

        if (subs) {
            for (NetworkDevicePtr dev : *subs) {
                auto sub = std::dynamic_pointer_cast<SubscriberBase>(dev);
                return [=](const boost::shared_ptr<RosType const> &ros_msg) {
                    using ScType = decltype(ros2sc(*ros_msg));
                    call_update_contacts(ros::Time::now().toSec());
                    mutex.lock();
                    auto sc_msg = std::make_shared<Message<ScType>>(ros2sc(*ros_msg));
                    sub->accept(sc_msg);
                    send_messages();
                    mutex.unlock();
                };
            }
        }

        std::cout << "Failed to create ROS to SCRIMMAGE subscriber (callback) " << std::endl;
        std::cout << "Network name: " << network_name << std::endl;
        std::cout << "Topic name: " << topic_name << std::endl;
        return [=](const boost::shared_ptr<RosType const>&/*ros_msg*/) { };
    }

    template <class RosType, class ScrimmageResponseType,
              class Sc2RosResFunc>
    boost::function<bool(typename RosType::Request &, typename RosType::Response &)>
    srv_cb(const std::string &service_name,
           scrimmage::Service sc_service_func,
           Sc2RosResFunc sc2ros_response_func) {
        auto ros2sc_req_func = [&](typename RosType::Request &ros_req) {return 0;};
        return srv_cb<RosType, ScrimmageResponseType>(
            service_name, sc_service_func, ros2sc_req_func, sc2ros_response_func);
    }

    template <class RosType, class ScrimmageResponseType,
              class Ros2ScRequestFunc, class Sc2RosResFunc>
    boost::function<bool(typename RosType::Request &, typename RosType::Response &)>
    srv_cb(const std::string &service_name,
           scrimmage::Service sc_service_func,
           Ros2ScRequestFunc ros2sc_request_func,
           Sc2RosResFunc sc2ros_response_func) {

        return [=](typename RosType::Request &ros_req, typename RosType::Response &ros_res) {

            call_update_contacts(ros::Time::now().toSec());

            auto err_msg = [&](const std::string &preface) {
                std::cout << preface << " in advertised_service \""
                    << service_name << "\"" << std::endl;
            };

            using ScReqType = decltype(ros2sc_request_func(ros_req));
            auto sc_req = std::make_shared<Message<ScReqType>>(ros2sc_request_func(ros_req));
            auto sc_req_base = std::dynamic_pointer_cast<MessageBase>(sc_req);
            auto sc_res_base = std::make_shared<MessageBase>();
            if (!sc_service_func(sc_req_base, sc_res_base)) {
                err_msg("call to sc_service_func failed");
                return false;
            }

            auto sc_res = std::dynamic_pointer_cast<Message<ScrimmageResponseType>>(sc_res_base);
            if (!sc_res) {
                std::stringstream ss;
                ss << "could not cast to scrimmage::MessagePtr<ScrimmageResponseType> "
                    << "(aka, scrimmage::MessagePtr<"
                    << boost::typeindex::type_id<ScrimmageResponseType>().pretty_name()
                    << ">)";
                err_msg(ss.str());
                return false;
            }

            ros_res = sc2ros_response_func(sc_res->data);
            return true;
        };
    }

    template <class RosType, class Ros2ScResFunc>
    void add_srv_client(ros::NodeHandle &nh,
        const std::string &sc_topic,
        Ros2ScResFunc ros2sc_response_func,
        const std::string &ros_topic = "") {

        auto nop = [&](auto msg){};
        add_srv_client<RosType, void>(
            nh, sc_topic, nop, ros2sc_response_func, ros_topic);
    }

    template <class RosType, class ScReqType, class Sc2RosReqFunc, class Ros2ScResFunc>
    void add_srv_client(ros::NodeHandle &nh,
        const std::string &sc_topic,
        Sc2RosReqFunc sc2ros_request_func,
        Ros2ScResFunc ros2sc_response_func,
        const std::string &ros_topic = "") {

        std::string topic = ros_topic == "" ? sc_topic : ros_topic;
        auto service_client =
            std::make_shared<ros::ServiceClient>(nh.serviceClient<RosType>(topic));

        auto call_service =
            [=](scrimmage::MessageBasePtr sc_req, scrimmage::MessageBasePtr &sc_res) {
                std::string suffix =
                    std::string("(sc_topic = ") + sc_topic + ", ros_topic = " + topic + ")";

                RosType srv;
                create_ros_req<ScReqType, Sc2RosReqFunc, RosType>(
                    sc_req, sc2ros_request_func, suffix, srv);

                if (!service_client->call(srv)) {
                    std::cout << "service call failed " << suffix << std::endl;
                    return false;
                }

                using ScResType = decltype(ros2sc_response_func(srv.response));
                auto sc_res_cast = std::make_shared<Message<ScResType>>(ros2sc_response_func(srv.response));
                sc_res = std::dynamic_pointer_cast<MessageBase>(sc_res_cast);
                return true;
            };

        entity_->services()[sc_topic] = call_service;
    }

 protected:
    template <class ScReqType,
              class Sc2RosReqFunc,
              class RosType>
    void
    // cppcheck-suppress passedByValue
    create_ros_req(typename std::enable_if_t<std::is_void<ScReqType>::value, MessageBasePtr> sc_req,
                   Sc2RosReqFunc sc2ros_req_func,
                   const std::string &err_msg, RosType &srv) {}

    template <class ScReqType,
              class Sc2RosReqFunc,
              class RosType>
    void
    create_ros_req(typename std::enable_if_t<!std::is_void<ScReqType>::value, MessageBasePtr> sc_req,
                   Sc2RosReqFunc sc2ros_req_func,
                   const std::string &err_msg, RosType &srv) {
        auto sc_req_cast =
            std::dynamic_pointer_cast<Message<ScReqType>>(sc_req);
        if (!sc_req_cast) {
            std::cout << "could not cast scrimmage::MessageBase request "
                << " to scrimmage::MessagePtr<"
                << boost::typeindex::type_id<ScReqType>().pretty_name()
                << "> " << err_msg << std::endl;
        }
        srv.request = sc2ros_req_func(sc_req_cast->data);
    }

#endif

 protected:
    void call_update_contacts(double t);
    void update_time(double t);
};

} // namespace scrimmage

#endif // INCLUDE_SCRIMMAGE_ENTITY_EXTERNAL_H_
