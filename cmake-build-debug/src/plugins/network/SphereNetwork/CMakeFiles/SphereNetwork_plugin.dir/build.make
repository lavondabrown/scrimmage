# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/lbrown62/devspace/clion-2017.3.4/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/lbrown62/devspace/clion-2017.3.4/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lbrown62/scrimmage/scrimmage

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lbrown62/scrimmage/scrimmage/cmake-build-debug

# Include any dependencies generated for this target.
include src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/depend.make

# Include the progress variables for this target.
include src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/progress.make

# Include the compile flags for this target's objects.
include src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/flags.make

src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/SphereNetwork.cpp.o: src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/flags.make
src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/SphereNetwork.cpp.o: ../src/plugins/network/SphereNetwork/SphereNetwork.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/SphereNetwork.cpp.o"
	cd /home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/network/SphereNetwork && /usr/bin/ccache /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SphereNetwork_plugin.dir/SphereNetwork.cpp.o -c /home/lbrown62/scrimmage/scrimmage/src/plugins/network/SphereNetwork/SphereNetwork.cpp

src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/SphereNetwork.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SphereNetwork_plugin.dir/SphereNetwork.cpp.i"
	cd /home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/network/SphereNetwork && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lbrown62/scrimmage/scrimmage/src/plugins/network/SphereNetwork/SphereNetwork.cpp > CMakeFiles/SphereNetwork_plugin.dir/SphereNetwork.cpp.i

src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/SphereNetwork.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SphereNetwork_plugin.dir/SphereNetwork.cpp.s"
	cd /home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/network/SphereNetwork && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lbrown62/scrimmage/scrimmage/src/plugins/network/SphereNetwork/SphereNetwork.cpp -o CMakeFiles/SphereNetwork_plugin.dir/SphereNetwork.cpp.s

src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/SphereNetwork.cpp.o.requires:

.PHONY : src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/SphereNetwork.cpp.o.requires

src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/SphereNetwork.cpp.o.provides: src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/SphereNetwork.cpp.o.requires
	$(MAKE) -f src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/build.make src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/SphereNetwork.cpp.o.provides.build
.PHONY : src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/SphereNetwork.cpp.o.provides

src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/SphereNetwork.cpp.o.provides.build: src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/SphereNetwork.cpp.o


# Object files for target SphereNetwork_plugin
SphereNetwork_plugin_OBJECTS = \
"CMakeFiles/SphereNetwork_plugin.dir/SphereNetwork.cpp.o"

# External object files for target SphereNetwork_plugin
SphereNetwork_plugin_EXTERNAL_OBJECTS =

plugin_libs/libSphereNetwork_plugin.so.0.0.1: src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/SphereNetwork.cpp.o
plugin_libs/libSphereNetwork_plugin.so.0.0.1: src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/build.make
plugin_libs/libSphereNetwork_plugin.so.0.0.1: src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../../../plugin_libs/libSphereNetwork_plugin.so"
	cd /home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/network/SphereNetwork && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SphereNetwork_plugin.dir/link.txt --verbose=$(VERBOSE)
	cd /home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/network/SphereNetwork && $(CMAKE_COMMAND) -E cmake_symlink_library ../../../../plugin_libs/libSphereNetwork_plugin.so.0.0.1 ../../../../plugin_libs/libSphereNetwork_plugin.so.0 ../../../../plugin_libs/libSphereNetwork_plugin.so

plugin_libs/libSphereNetwork_plugin.so.0: plugin_libs/libSphereNetwork_plugin.so.0.0.1
	@$(CMAKE_COMMAND) -E touch_nocreate plugin_libs/libSphereNetwork_plugin.so.0

plugin_libs/libSphereNetwork_plugin.so: plugin_libs/libSphereNetwork_plugin.so.0.0.1
	@$(CMAKE_COMMAND) -E touch_nocreate plugin_libs/libSphereNetwork_plugin.so

# Rule to build all files generated by this target.
src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/build: plugin_libs/libSphereNetwork_plugin.so

.PHONY : src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/build

src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/requires: src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/SphereNetwork.cpp.o.requires

.PHONY : src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/requires

src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/clean:
	cd /home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/network/SphereNetwork && $(CMAKE_COMMAND) -P CMakeFiles/SphereNetwork_plugin.dir/cmake_clean.cmake
.PHONY : src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/clean

src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/depend:
	cd /home/lbrown62/scrimmage/scrimmage/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lbrown62/scrimmage/scrimmage /home/lbrown62/scrimmage/scrimmage/src/plugins/network/SphereNetwork /home/lbrown62/scrimmage/scrimmage/cmake-build-debug /home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/network/SphereNetwork /home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/plugins/network/SphereNetwork/CMakeFiles/SphereNetwork_plugin.dir/depend

