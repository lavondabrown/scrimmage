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
<<<<<<< HEAD

#include <iostream>
#include <limits>
=======
#include <scrimmage/common/Time.h>

>>>>>>> upstream/master
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

<<<<<<< HEAD
=======
#include <iostream>
#include <limits>

#include <flightgear/MultiPlayer/mpmessages.hxx>
#include <flightgear/MultiPlayer/tiny_xdr.hxx>

>>>>>>> upstream/master
#include <GeographicLib/LocalCartesian.hpp>

using std::cout;
using std::endl;

namespace sc = scrimmage;

REGISTER_PLUGIN(scrimmage::Autonomy,
                scrimmage::autonomy::FlightGearMultiplayer,
                FlightGearMultiplayer_plugin)

namespace scrimmage {
namespace autonomy {

<<<<<<< HEAD
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
=======
FlightGearMultiplayer::FlightGearMultiplayer() :
    callsign_("scrimmage"),
    data_socket_(std::make_shared<netSocket>()),
    earth_(std::make_shared<GeographicLib::Geocentric>(
               GeographicLib::Constants::WGS84_a(),
               GeographicLib::Constants::WGS84_f())),
    angles_to_jsbsim_(0, Angles::Type::EUCLIDEAN, Angles::Type::GPS) {
}

void FlightGearMultiplayer::init(std::map<std::string, std::string> &params) {

    std::string server_ip = sc::get<std::string>("server_ip", params, "127.0.0.1");
    int server_port = sc::get<int>("server_port", params, 5000);
    callsign_ = sc::get<std::string>("callsign", params, "scrimmage");

    net_address_.set(server_ip.c_str(), server_port);
    if (data_socket_->open(false)  == 0) { // Open UDP socket
        std::cout << "Failed to open connection to: " << endl;
        cout << "Server IP: " << net_address_.getIP() << endl;
        cout << "Server Port: " << net_address_.getPort() << endl;
    }
}

scrimmage::Quaternion FlightGearMultiplayer::fromLonLatRad(float lon, float lat) {
    // TODO : This transformation was taken from the Flight Gear Multiplayer
    // server, we should convert this to using our own quaternion class, but
    // for now, this works.

    // Eigen::AngleAxisd R_a(sc::Angles::deg2rad(lon), Eigen::Vector3d::UnitZ());
    // Eigen::AngleAxisd R_b(sc::Angles::deg2rad(lat),
    // Eigen::Vector3d::UnitX()); Eigen::Quaterniond rot2 = R_a * R_b;

    float zd2 = static_cast<float>(0.5) * lon;
    float yd2 = static_cast<float>(-0.25) * static_cast<float>(M_PI) - static_cast<float>(0.5) * lat;
    float Szd2 = sin(zd2);
    float Syd2 = sin(yd2);
    float Czd2 = cos(zd2);
    float Cyd2 = cos(yd2);
    scrimmage::Quaternion quat(Czd2 * Cyd2, -Szd2 * Syd2, Czd2 * Syd2, Szd2 * Cyd2);
    return quat;
}

bool FlightGearMultiplayer::step_autonomy(double t, double dt) {
    int msg_size = sizeof(T_MsgHdr) + sizeof(T_PositionMsg);

    // Create the flight gear header
    struct T_MsgHdr header_msg;
    header_msg.Magic = XDR_encode<uint32_t>(MSG_MAGIC);
    header_msg.Version = XDR_encode<uint32_t>(PROTO_VER);
    header_msg.MsgId = XDR_encode<uint32_t>(FGFS::POS_DATA);
    header_msg.MsgLen = XDR_encode<uint32_t>(msg_size);
    header_msg.RadarRange = XDR_decode<float>(15);
    header_msg.ReplyPort = XDR_decode<uint32_t>(0);
    snprintf(header_msg.Name, MAX_CALLSIGN_LEN, "%s", callsign_.c_str());

    // Create the flight gear position msg
    struct T_PositionMsg pos_msg;
    snprintf(pos_msg.Model, MAX_MODEL_NAME_LEN, "%s", "Aircraft/c172p/Models/c172p.xml");
    pos_msg.time = XDR_encode64<float>(time_->t());
    pos_msg.lag = XDR_encode64<float>(time_->t());

    // Compute ECEF coordinates from x/y/z lat/lon/alt
>>>>>>> upstream/master
    double lat, lon, alt;
    parent_->projection()->Reverse(state_->pos()(0), state_->pos()(1),
                                   state_->pos()(2),
                                   lat, lon, alt);
<<<<<<< HEAD

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

=======
    double ECEF_X, ECEF_Y, ECEF_Z;
    earth_->Forward(lat, lon, alt, ECEF_X, ECEF_Y, ECEF_Z);

    pos_msg.position[0] = XDR_encode64<double>(ECEF_X);
    pos_msg.position[1] = XDR_encode64<double>(ECEF_Y);
    pos_msg.position[2] = XDR_encode64<double>(ECEF_Z);

    // Convert local heading to GPS heading
    angles_to_jsbsim_.set_angle(sc::Angles::rad2deg(state_->quat().yaw()));
    sc::Quaternion local_quat(state_->quat().roll(), state_->quat().pitch(),
                              sc::Angles::deg2rad(angles_to_jsbsim_.angle()));

    // Convert local quaternion to ECEF coordinate
    scrimmage::Quaternion rot = this->fromLonLatRad(sc::Angles::deg2rad(lon),
                                                    sc::Angles::deg2rad(lat));

    // The FlightGear Multiplayer packet expects the orientation to be in
    // angle-axis form, where the axis magnitude is the rotation angle.
    Eigen::AngleAxisd ang_axis(rot * local_quat);
    Eigen::Vector3d ang_axis_mod = ang_axis.axis().normalized() * ang_axis.angle();

    pos_msg.orientation[0] = XDR_encode<float>(ang_axis_mod(0));
    pos_msg.orientation[1] = XDR_encode<float>(ang_axis_mod(1));
    pos_msg.orientation[2] = XDR_encode<float>(ang_axis_mod(2));

    // TODO conversion
    pos_msg.linearVel[0] = XDR_encode<float>(0);
    pos_msg.linearVel[1] = XDR_encode<float>(0);
    pos_msg.linearVel[2] = XDR_encode<float>(0);

    pos_msg.angularVel[0] = XDR_encode<float>(0);
    pos_msg.angularVel[1] = XDR_encode<float>(0);
    pos_msg.angularVel[2] = XDR_encode<float>(0);

    pos_msg.linearAccel[0]= XDR_encode<float>(0);
    pos_msg.linearAccel[1]= XDR_encode<float>(0);
    pos_msg.linearAccel[2]= XDR_encode<float>(0);

    pos_msg.angularAccel[0] = XDR_encode<float>(0);
    pos_msg.angularAccel[1] = XDR_encode<float>(0);
    pos_msg.angularAccel[2] = XDR_encode<float>(0);

    // Copy header and position data structs into memory buffer
    char * msg = new char[msg_size];
    std::memcpy(msg, &header_msg, sizeof(T_MsgHdr));
    std::memcpy(msg+sizeof(T_MsgHdr), &pos_msg, sizeof(T_PositionMsg));

    data_socket_->sendto(msg, msg_size, 0, &net_address_);
    delete[] msg;
>>>>>>> upstream/master

    return true;
}
} // namespace autonomy
} // namespace scrimmage
