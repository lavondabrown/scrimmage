# Install script for directory: /home/lbrown62/scrimmage/scrimmage/src/plugins/controller

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
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/AircraftToSingleIntegratorController/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/DoubleIntegratorControllerDirect/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/DoubleIntegratorControllerVelYaw/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/DoubleIntegratorControllerWaypoint/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/FixedWing6DOFControllerPID/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/FixedWing6DOFControllerROS/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/JSBSimControlControllerDirect/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/JSBSimControlControllerHeadingPID/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/JSBSimModelControllerDirect/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/JSBSimModelControllerHeadingPID/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/JoystickController/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/MultirotorControllerOmega/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/MultirotorControllerPID/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/RigidBody6DOFControllerPID/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/RigidBody6DOFControllerROS/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/SimpleAircraftControllerPID/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/SimpleCarControllerHeading/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/SimpleQuadrotorControllerLQR/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/SingleIntegratorControllerSimple/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/SingleIntegratorControllerWaypoint/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/Unicycle3DControllerDirect/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/Unicycle3DControllerPID/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/UnicycleControllerDirect/cmake_install.cmake")
  include("/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/UnicycleControllerPoint/cmake_install.cmake")

endif()

