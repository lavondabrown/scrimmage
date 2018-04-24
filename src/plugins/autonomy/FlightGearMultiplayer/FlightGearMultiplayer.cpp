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
     //double server_ip = sc::get<std::string>("server_ip", params, "127.0.0.1");
     //int server_port = sc::get<int>("server_port", params, 5000);
    const sc_ip;
    get_vec(sc_ip)


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

    float velx, vel2, vel3;
    parent_->projection()->Reverse(state_->vel()(0), state_->vel()(1),
                                   state_->vel()(2),
                                   vel1, vel2, vel3);
    float ang_vel1, ang_vel2, ang_vel3;
    parent_->projection()->Reverse(state_->ang_vel()(0), state_->ang_vel()(1),
                                   state_->ang_vel()(2),
                                   lat, lon, alt);

    // need to find corresponding values on scrimmage state_variable

   // send(client, lat, strlen(lat) , 0 );


    //T_PositionMsg.position[X] = lat; //mpmessages.hxx

    //encode position and orientation using XDR
    char model = Entity1[sizeof(Entity1)];

    double time = XDR_encode64<double> ();

    double lag = XDR_encode62<double> ();

    double Pos = XDR_encode64<double> (lat);
    double Pos = XDR_encode64<double> (lon);
    double Pos = XDR_encode64<double> (alt);

    float Ori = XDR_encode<float> ();
    float Ori = XDR_encode<float> ();
    float Ori = XDR_encode<float> ();

    float linvel = XDR_encode<float> (velX);
    float linvel = XDR_encode<float> (velY);
    float linvel = XDR_encode<float> (velZ);

    float angvel = XDR_encode<float> (ang_vel1);
    float angvel = XDR_encode<float> (ang_vel2);
    float angvel = XDR_encode<float> (ang_vel3);

    float linaccel = XDR_encode<float> ();
    float linaccel = XDR_encode<float> ();
    float linaccel = XDR_encode<float> ();

    float angaccel = XDR_encode<float> ();
    float angaccel = XDR_encode<float> ();
    float angaccel = XDR_encode<float> ();

    //flightgear position msg struct
    struct T_PositionMsg sc_pos;
    sc_pos.Model = model;
    sc_pos.time = time;
    sc_pos.lag = lag;
    sc_pos.position[3] = Pos;
    sc_pos.orientation[3]= Ori;
    sc_pos.linearVel[3]= linvel;
    sc_pos.angularVel[3]= angvel;
    sc_pos.linearAccel[3]= linaccel;
    sc_pos.angularAccel[3]= angaccel;

    //send message to flightgear server once encoded
            //MsgId == FGFS::POS_DATA

    m_DataSocket->sendto (sc_pos, sizeof (sc_pos), 0, sc_ip);



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
