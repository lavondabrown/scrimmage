# TODO Find fgms code. include_directories() to point at the ./fgms/src
# directory. Also, get the libraries that are built by fgms and allow them to
# be used in the target_link_libraries below:
<<<<<<< HEAD
find_package(FGMS)
message("============> HELLO!!! [Plugin CMakeLists.txt] ${FGMS_FOUND}")
if(NOT FGMS_FOUND)
    return()
=======
find_package(FGMS QUIET)
if(NOT FGMS_FOUND)
  return()
>>>>>>> upstream/master
endif()

include_directories(${FGMS_INCLUDE_DIRS})

<<<<<<< HEAD
=======
# message("==> ${FGMS_INCLUDE_DIRS}")

add_definitions(-DSG_HAVE_STD_INCLUDES=1)
add_definitions(-DFG_NDEBUG=1)

>>>>>>> upstream/master
#--------------------------------------------------------
# Library Creation
#--------------------------------------------------------
SET (LIBRARY_NAME FlightGearMultiplayer_plugin)
SET (LIB_MAJOR 0)
SET (LIB_MINOR 0)
SET (LIB_RELEASE 1)

file(GLOB SRCS *.cpp) #does this need to be *.cxx too

ADD_LIBRARY(${LIBRARY_NAME} SHARED
  ${SRCS}
  )

TARGET_LINK_LIBRARIES(${LIBRARY_NAME}
<<<<<<< HEAD
        ${FGMS_LIBRARIES}
=======
  ${FGMS_LIBRARIES}
>>>>>>> upstream/master
  )

SET (_soversion ${LIB_MAJOR}.${LIB_MINOR}.${LIB_RELEASE})

set_target_properties(${LIBRARY_NAME} PROPERTIES
  SOVERSION ${LIB_MAJOR}
  VERSION ${_soversion}
  LIBRARY_OUTPUT_DIRECTORY ${PROJECT_PLUGIN_LIBS_DIR}
  )

install(TARGETS ${LIBRARY_NAME}
  # IMPORTANT: Add the library to the "export-set"
  EXPORT ${PROJECT_NAME}-targets
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib/${PROJECT_NAME}/plugin_libs
<<<<<<< HEAD
)
=======
  )
>>>>>>> upstream/master

# Push up the PROJECT_PLUGINS variable
set(PROJECT_PLUGINS ${PROJECT_PLUGINS} ${LIBRARY_NAME} PARENT_SCOPE)
