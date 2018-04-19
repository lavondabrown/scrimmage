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

#include <scrimmage/plugins/autonomy/FlightGearMultiplayer/FlightGearMultiplayer.h>

#include <scrimmage/plugin_manager/RegisterPlugin.h>
#include <scrimmage/entity/Entity.h>
#include <scrimmage/math/State.h>
#include <scrimmage/parse/ParseUtils.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <iostream>
#include <limits>

#include <GeographicLib/LocalCartesian.hpp>

// #include <fgms/src/server/fg_server.hxx>

using std::cout;
using std::endl;

namespace sc = scrimmage;

REGISTER_PLUGIN(scrimmage::Autonomy,
                scrimmage::autonomy::FlightGearMultiplayer,
                FlightGearMultiplayer_plugin)

namespace scrimmage {
namespace autonomy {

FlightGearMultiplayer::FlightGearMultiplayer() {
}

void FlightGearMultiplayer::init(std::map<std::string, std::string> &params) {
    // double server_ip = sc::get<std::string>("server_ip", params, "127.0.0.1");
    // int server_port = sc::get<int>("server_port", params, 5000);

    // TODO: Open a socket to the multiplayer server

  //  int socket_fgms = socket(AF_INET, SOCK_DGRAM, 0);
   // int connect(int socket_fgms, const struct sockaddr *addr,
   //             socklen_t addrlen);
}

bool FlightGearMultiplayer::step_autonomy(double t, double dt) {

    // User Documentation about using FlightGear Multiplayer: OK
    // http://wiki.flightgear.org/Howto:Multiplayer

    // Developer documentation for the UDP packet that is sent from a Flight
    // gear client to the multiplayer server: OK
    // http://wiki.flightgear.org/Multiplayer_protocol


    // Get lat, lon, alt from x, y, z position
    double lat, lon, alt;
    parent_->projection()->Reverse(state_->pos()(0), state_->pos()(1),
                                   state_->pos()(2),
                                   lat, lon, alt);

    //////////////////////////////////////////////////////
    // TODO: Create XDR packet from state_ variable.  We can leverage the
    // socket code and XDR packet definitions in the actual flight gear
    // multiplayer server code. So, in a directory (like ~/repos/3rd-party),
    // clone the flight gear multiplayer server.... ***Done
    //
    // git clone https://github.com/FlightGear/fgms.git ***Done
    // build it... mkdir build && cd build && make ***Done
    // We need to be able to use the files at: ***OK
    // fgms/src/flightgear/MultiPlayer/

    // Look at how the XDR_encode<T>() function is used in
    // ./src/server/fg_server.cxx to create a message and send it with the
    // m_DataSocket->sendto class. We need to fill in the appropriate data
    // elements to create the flight gear position message (with information
    // from our state_ variable) and send it to the multiplayer server using
    // the m_DataSocket->sendto method. m_DataSocket is a netSocket class in
    // the multiplayer server code.

    //***line 1319-1320 in fg_server.cxx
    //***state_variable -- is that the x,y,and z position?  lat, lon, alt? or more state info other than position?
    //***XDR = eXternal Data Representation
    //***encoding = converting from local representation to XDR
    //***decoding = converting from XDR to local representation

    // In order to use the multiplayer server code, this plugin needs to be
    // able to "find" the fgms code. This can be handcoded at first, but
    // eventually, I want this plugin to not build if the user didn't specify a
    // CMake varaible that points to the fgms "build tree". For example, if the
    // user wants to build this plugin, they should type:
    // cmake .. -DFGMS_ROOT=~/repos/3rd-party/fgms
    //
    //***any examples in scrimmage where this is currently done? Where is the line drawn between handcoded and Cmake?
    //***
    //
    // If the user doesn't specify FGMS_ROOT variable, then this plugin
    // shouldn't build.


    return true;
}
} // namespace autonomy
} // namespace scrimmage
