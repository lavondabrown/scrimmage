# Install script for directory: /home/lbrown62/scrimmage/scrimmage/src/plugins/autonomy

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/autonomy/ArduPilot/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/autonomy/AuctionAssign/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/autonomy/AvoidEntityMS/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/autonomy/AvoidWalls/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/autonomy/Boids/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/autonomy/Control3D/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/autonomy/ExternalControl/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/autonomy/FlightGearMultiplayer/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/autonomy/MOOSAutonomy/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/autonomy/MotorSchemas/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/autonomy/MoveToGoalMS/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/autonomy/MultirotorTests/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/autonomy/Predator/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/autonomy/PyAutonomy/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/autonomy/QuadTest/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/autonomy/ROSAutonomy/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/autonomy/ROSControl/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/autonomy/Straight/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/autonomy/TrajectoryRecordPlayback/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/autonomy/TutorialOpenAIAutonomy/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/autonomy/WaypointFollower/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/autonomy/WaypointGenerator/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/autonomy/follow/cmake_install.cmake")

endif()

