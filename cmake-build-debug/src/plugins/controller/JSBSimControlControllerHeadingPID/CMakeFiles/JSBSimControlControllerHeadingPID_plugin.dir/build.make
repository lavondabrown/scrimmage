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
include src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/depend.make

# Include the progress variables for this target.
include src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/progress.make

# Include the compile flags for this target's objects.
include src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/flags.make

src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/JSBSimControlControllerHeadingPID.cpp.o: src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/flags.make
src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/JSBSimControlControllerHeadingPID.cpp.o: ../src/plugins/controller/JSBSimControlControllerHeadingPID/JSBSimControlControllerHeadingPID.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/JSBSimControlControllerHeadingPID.cpp.o"
	cd /home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/JSBSimControlControllerHeadingPID && /usr/bin/ccache /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/JSBSimControlControllerHeadingPID.cpp.o -c /home/lbrown62/scrimmage/scrimmage/src/plugins/controller/JSBSimControlControllerHeadingPID/JSBSimControlControllerHeadingPID.cpp

src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/JSBSimControlControllerHeadingPID.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/JSBSimControlControllerHeadingPID.cpp.i"
	cd /home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/JSBSimControlControllerHeadingPID && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lbrown62/scrimmage/scrimmage/src/plugins/controller/JSBSimControlControllerHeadingPID/JSBSimControlControllerHeadingPID.cpp > CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/JSBSimControlControllerHeadingPID.cpp.i

src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/JSBSimControlControllerHeadingPID.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/JSBSimControlControllerHeadingPID.cpp.s"
	cd /home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/JSBSimControlControllerHeadingPID && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lbrown62/scrimmage/scrimmage/src/plugins/controller/JSBSimControlControllerHeadingPID/JSBSimControlControllerHeadingPID.cpp -o CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/JSBSimControlControllerHeadingPID.cpp.s

src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/JSBSimControlControllerHeadingPID.cpp.o.requires:

.PHONY : src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/JSBSimControlControllerHeadingPID.cpp.o.requires

src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/JSBSimControlControllerHeadingPID.cpp.o.provides: src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/JSBSimControlControllerHeadingPID.cpp.o.requires
	$(MAKE) -f src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/build.make src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/JSBSimControlControllerHeadingPID.cpp.o.provides.build
.PHONY : src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/JSBSimControlControllerHeadingPID.cpp.o.provides

src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/JSBSimControlControllerHeadingPID.cpp.o.provides.build: src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/JSBSimControlControllerHeadingPID.cpp.o


# Object files for target JSBSimControlControllerHeadingPID_plugin
JSBSimControlControllerHeadingPID_plugin_OBJECTS = \
"CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/JSBSimControlControllerHeadingPID.cpp.o"

# External object files for target JSBSimControlControllerHeadingPID_plugin
JSBSimControlControllerHeadingPID_plugin_EXTERNAL_OBJECTS =

plugin_libs/libJSBSimControlControllerHeadingPID_plugin.so.0.0.1: src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/JSBSimControlControllerHeadingPID.cpp.o
plugin_libs/libJSBSimControlControllerHeadingPID_plugin.so.0.0.1: src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/build.make
plugin_libs/libJSBSimControlControllerHeadingPID_plugin.so.0.0.1: src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../../../plugin_libs/libJSBSimControlControllerHeadingPID_plugin.so"
	cd /home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/JSBSimControlControllerHeadingPID && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/link.txt --verbose=$(VERBOSE)
	cd /home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/JSBSimControlControllerHeadingPID && $(CMAKE_COMMAND) -E cmake_symlink_library ../../../../plugin_libs/libJSBSimControlControllerHeadingPID_plugin.so.0.0.1 ../../../../plugin_libs/libJSBSimControlControllerHeadingPID_plugin.so.0 ../../../../plugin_libs/libJSBSimControlControllerHeadingPID_plugin.so

plugin_libs/libJSBSimControlControllerHeadingPID_plugin.so.0: plugin_libs/libJSBSimControlControllerHeadingPID_plugin.so.0.0.1
	@$(CMAKE_COMMAND) -E touch_nocreate plugin_libs/libJSBSimControlControllerHeadingPID_plugin.so.0

plugin_libs/libJSBSimControlControllerHeadingPID_plugin.so: plugin_libs/libJSBSimControlControllerHeadingPID_plugin.so.0.0.1
	@$(CMAKE_COMMAND) -E touch_nocreate plugin_libs/libJSBSimControlControllerHeadingPID_plugin.so

# Rule to build all files generated by this target.
src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/build: plugin_libs/libJSBSimControlControllerHeadingPID_plugin.so

.PHONY : src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/build

src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/requires: src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/JSBSimControlControllerHeadingPID.cpp.o.requires

.PHONY : src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/requires

src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/clean:
	cd /home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/JSBSimControlControllerHeadingPID && $(CMAKE_COMMAND) -P CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/cmake_clean.cmake
.PHONY : src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/clean

src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/depend:
	cd /home/lbrown62/scrimmage/scrimmage/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lbrown62/scrimmage/scrimmage /home/lbrown62/scrimmage/scrimmage/src/plugins/controller/JSBSimControlControllerHeadingPID /home/lbrown62/scrimmage/scrimmage/cmake-build-debug /home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/JSBSimControlControllerHeadingPID /home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/plugins/controller/JSBSimControlControllerHeadingPID/CMakeFiles/JSBSimControlControllerHeadingPID_plugin.dir/depend

