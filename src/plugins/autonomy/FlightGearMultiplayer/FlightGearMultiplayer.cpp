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

#include <iostream>
#include <limits>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#include <GeographicLib/LocalCartesian.hpp>

#include <fgms/src/server/fg_server.hxx>

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
     double server_ip = sc::get<std::string>("server_ip", params, "127.0.0.1");
     int server_port = sc::get<int>("server_port", params, 5000);

    // TODO: Open a socket to the multiplayer server

    int client, connection_status;
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = server_ip;

    client = socket(AF_INET, SOCK_DGRAM, 0);

    if (client < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
    else
        printf("\n Socket creation successful \n");

    connection_status = connect(client, (struct sockaddr *) &server_addr, sizeof(server_addr));

    if (connection_status < 0)
    {
        printf("\n Connection Failed \n");
        return -1;
    }
    else
        printf("\n Connection successful \n");

    //--multiplay=direction,10,ip.address,port
    //--callsign=anything
    //--multiplay=in,10,127.0.0.1,5000   ----------> sending state variables to SC from FG
    //--multiplay=out,10,127.0.0.1,5001   ----------> will FG be sending SC anything ? No, Kevin is flying human
    // pilot through scrimmage and leveraging the JSBSim controller to update flight gear viewer
}

bool FlightGearMultiplayer::step_autonomy(double t, double dt) {

    // User Documentation about using FlightGear Multiplayer: OK
    // http://wiki.flightgear.org/Howto:Multiplayer

    //http://wiki.flightgear.org/Howto:Set_up_a_multiplayer_server

    // Developer documentation for the UDP packet that is sent from a Flight
    // gear client to the multiplayer server: OK
    // http://wiki.flightgear.org/Multiplayer_protocol


    // Get lat, lon, alt from x, y, z position //also need to get roll (X), pitch(Y), and yaw (Z) orientation
    double lat, lon, alt;
    parent_->projection()->Reverse(state_->pos()(0), state_->pos()(1),
                                   state_->pos()(2),
                                   lat, lon, alt);

    send(client, lat, strlen(lat) , 0 );

    //Position messages

    //The data of position message is more complicated and is composed of a two parts. The first part contain
    // information needed to place an aircraft model in the right position and orientation. The second part contain
    // property values used for animating the model, provided the user on the receiving end would have that aircraft
    // installed.

    //First part:
    //      -Positions are in with respect to the Earth centered frame.
    //      -Orientations are with respect to the X, Y and Z axis of the Earth centered frame, stored in the angle axis
    //          representation where the angle is coded into the axis length.
    //      -Velocities are along the X, Y and Z directions of the Earth centered frame.
    //      -Angular accelerations are in two parts of the three dimensional angular velocity vector with respect to the
    //          Earth centered frame measured in the Earth centered frame.
    //      -Linear accelerations are in two parts of the three dimensional linear acceleration vector with respect to
    //          the Earth centered frame measured in the Earth centered frame.

    //The first part contain these fields in exactly that order:

    //Field 	Size 	Remarks
    //ModelName 	96 bytes 	Zero terminated array of characters representing the aircraft model (/sim/model/path) used by the user
    //time 	8 bytes 	Representing the time when this message was generated double
    //lag 	8 bytes 	Time offset for network lag double
    //PosX 	8 bytes 	XDR encoded double value, X-ccordinate of users position
    //PosY 	8 bytes 	XDR encoded double value, Y-ccordinate of users position
    //PosZ 	8 bytes 	XDR encoded double value, z-ccordinate of users position
    //OriX 	4 bytes 	XDR encoded float value, X-orientation of the user
    //OriY 	4 bytes 	XDR encoded float value, Y-orientation of the user
    //OriZ 	4 bytes 	XDR encoded float value, Z-orientation of the user
    //VelX 	4 bytes 	XDR encoded float value, velocity of the user in X direction
    //VelY 	4 bytes 	XDR encoded float value, velocity of the user in Y direction
    //VelZ 	4 bytes 	XDR encoded float value, velocity of the user in Z direction
    //AV1 	4 bytes 	XDR encoded float value, 1. part of the three dimensional angular velocity vector
    //AV2 	4 bytes 	XDR encoded float value, 2. part of the three dimensional angular velocity vector
    //AV3 	4 bytes 	XDR encoded float value, 3. part of the three dimensional angular velocity vector
    //LA1 	4 bytes 	XDR encoded float value, 1. part of the three dimensional linear accelaration vector
    //LA2 	4 bytes 	XDR encoded float value, 2. part of the three dimensional linear accelaration vector
    //LA3 	4 bytes 	XDR encoded float value, 3. part of the three dimensional linear accelaration vector
    //AA1 	4 bytes 	XDR encoded float value, 1. part of the three dimensional angular accelaration vector
    //AA2 	4 bytes 	XDR encoded float value, 2. part of the three dimensional angular accelaration vector
    //AA3 	4 bytes 	XDR encoded float value, 3. part of the three dimensional angular accelaration vector
    //pad 	up to 8 bytes 	For padding the data to a multiple of 8 bytes

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
