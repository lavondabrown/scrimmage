# - Config file for the FooBar package
# It defines the following variables
#  SCRIMMAGE_INCLUDE_DIRS - include directories for FooBar
#  SCRIMMAGE_LIBRARIES    - libraries to link against

# Compute paths
get_filename_component(PROJECT_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)

## Our library dependencies (contains definitions for IMPORTED targets)
include("${PROJECT_CMAKE_DIR}/scrimmage-targets.cmake")

set(SCRIMMAGE_INCLUDE_DIRS "/home/lbrown62/scrimmage/scrimmage/include;/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/msgs;/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/proto")
set(SCRIMMAGE_LIBRARIES "scrimmage-msgs;scrimmage-protos;scrimmage")
set(SCRIMMAGE_VIEWER_LIB "scrimmage-viewer")
set(SCRIMMAGE_PLUGINS "ArduPilot_plugin;AuctionAssign_plugin;AvoidEntityMS_plugin;AvoidWalls_plugin;Boids_plugin;Control3D_plugin;ExternalControl_plugin;MotorSchemas_plugin;MoveToGoalMS_plugin;MultirotorTests_plugin;Predator_plugin;PyAutonomy_plugin;QuadTest_plugin;Straight_plugin;TrajectoryRecordPlayback_plugin;TutorialOpenAIAutonomy_plugin;WaypointFollower_plugin;WaypointGenerator_plugin;follow_plugin;ContactBlobCamera_plugin;NoisyContacts_plugin;NoisyState_plugin;RayTrace_plugin;RigidBody6DOFStateSensor_plugin;SimpleCamera_plugin;TutorialOpenAISensor_plugin;DoubleIntegrator_plugin;FixedWing6DOF_plugin;JSBSimControl_plugin;JSBSimModel_plugin;Multirotor_plugin;RigidBody6DOF_plugin;SimpleAircraft_plugin;SimpleCar_plugin;SimpleQuadrotor_plugin;SingleIntegrator_plugin;UUV6DOF_plugin;Unicycle_plugin;Unicycle3D_plugin;AircraftToSingleIntegratorController_plugin;DoubleIntegratorControllerDirect_plugin;DoubleIntegratorControllerVelYaw_plugin;DoubleIntegratorControllerWaypoint_plugin;FixedWing6DOFControllerPID_plugin;JSBSimControlControllerDirect_plugin;JSBSimControlControllerHeadingPID_plugin;JSBSimModelControllerDirect_plugin;JSBSimModelControllerHeadingPID_plugin;JoystickController_plugin;MultirotorControllerOmega_plugin;MultirotorControllerPID_plugin;RigidBody6DOFControllerPID_plugin;SimpleAircraftControllerPID_plugin;SimpleCarControllerHeading_plugin;SimpleQuadrotorControllerLQR_plugin;SingleIntegratorControllerSimple_plugin;SingleIntegratorControllerWaypoint_plugin;Unicycle3DControllerDirect_plugin;Unicycle3DControllerPID_plugin;UnicycleControllerDirect_plugin;UnicycleControllerPoint_plugin;SimpleCaptureMetrics_plugin;SimpleCollisionMetrics_plugin;Boundary_plugin;BulletCollision_plugin;GroundCollision_plugin;MapGen2D_plugin;SimpleCapture_plugin;SimpleCollision_plugin;GlobalNetwork_plugin;LocalNetwork_plugin;SphereNetwork_plugin")
set(SCRIMMAGE_ENABLE_PYTHON_BINDINGS "ON")

###############################################################################
# Include references to the important 3rd-party libraries and utilities that
# scrimmage uses:
###############################################################################

# jsbsim
set(SCRIMMAGE_JSBSIM_FOUND "TRUE")
set(SCRIMMMGE_JSBSIM_LIBRARIES "/opt/scrimmage/lib/libJSBSim.so;/opt/scrimmage/lib/libJSBSim.so")
set(SCRIMMAGE_JSBSIM_INCLUDE_DIR "/opt/scrimmage/include/JSBSim;/opt/scrimmage/include/JSBSim/JSBSim")

# geographiclib
set(SCRIMMAGE_GeographicLib_FOUND TRUE)
set(SCRIMMAGE_GeographicLib_INCLUDE_DIRS "/usr/include")
set(SCRIMMAGE_GeographicLib_LIBRARIES "/usr/lib/x86_64-linux-gnu/libGeographic.so")

# protobuf
set(SCRIMMAGE_PROTOBUF_FOUND TRUE)
set(SCRIMMAGE_PROTOBUF_PROTOC_EXECUTABLE "/opt/scrimmage/bin/protoc")
set(SCRIMMAGE_PROTOBUF_LIBRARIES "/opt/scrimmage/lib/libprotobuf.so;-lpthread")
set(SCRIMMAGE_PROTOBUF_INCLUDE "/opt/scrimmage/include")

# grpc
set(SCRIMMAGE_GRPC_FOUND "TRUE")
set(SCRIMMAGE_GRPC_CPP_PLUGIN "/opt/scrimmage/bin/grpc_cpp_plugin")
set(SCRIMMAGE_GRPC_PYTHON_PLUGIN "/opt/scrimmage/bin/grpc_python_plugin")
set(SCRIMMAGE_GRPC_LIBRARIES "/opt/scrimmage/lib/libgrpc++.so;/opt/scrimmage/lib/libgrpc.so;/opt/scrimmage/lib/libgpr.so")
set(SCRIMMAGE_GRPC_INCLUDE_DIRS "")

# python
set(SCRIMMAGE_PYTHON_LIBRARIES "/usr/lib/x86_64-linux-gnu/libpython2.7.so")
set(SCRIMMAGE_PYTHON_INCLUDE_DIRS "/usr/include/python2.7")
set(SCRIMMAGE_PYTHON_FOUND TRUE)
set(SCRIMMAGE_PYTHONLIBS_VERSION_STRING "2.7.12")
set(SCRIMMAGE_PYBIND11_PYTHON_VERSION "")
set(SCRIMMAGE_PYBIND11_INCLUDE_DIRS "/opt/scrimmage/include;/usr/include/python2.7")
