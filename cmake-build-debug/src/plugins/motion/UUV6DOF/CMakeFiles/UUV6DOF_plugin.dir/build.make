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
include src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/depend.make

# Include the progress variables for this target.
include src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/progress.make

# Include the compile flags for this target's objects.
include src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/flags.make

src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/UUV6DOF.cpp.o: src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/flags.make
src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/UUV6DOF.cpp.o: ../src/plugins/motion/UUV6DOF/UUV6DOF.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/UUV6DOF.cpp.o"
	cd /home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/motion/UUV6DOF && /usr/bin/ccache /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UUV6DOF_plugin.dir/UUV6DOF.cpp.o -c /home/lbrown62/scrimmage/scrimmage/src/plugins/motion/UUV6DOF/UUV6DOF.cpp

src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/UUV6DOF.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UUV6DOF_plugin.dir/UUV6DOF.cpp.i"
	cd /home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/motion/UUV6DOF && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lbrown62/scrimmage/scrimmage/src/plugins/motion/UUV6DOF/UUV6DOF.cpp > CMakeFiles/UUV6DOF_plugin.dir/UUV6DOF.cpp.i

src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/UUV6DOF.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UUV6DOF_plugin.dir/UUV6DOF.cpp.s"
	cd /home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/motion/UUV6DOF && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lbrown62/scrimmage/scrimmage/src/plugins/motion/UUV6DOF/UUV6DOF.cpp -o CMakeFiles/UUV6DOF_plugin.dir/UUV6DOF.cpp.s

src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/UUV6DOF.cpp.o.requires:

.PHONY : src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/UUV6DOF.cpp.o.requires

src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/UUV6DOF.cpp.o.provides: src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/UUV6DOF.cpp.o.requires
	$(MAKE) -f src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/build.make src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/UUV6DOF.cpp.o.provides.build
.PHONY : src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/UUV6DOF.cpp.o.provides

src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/UUV6DOF.cpp.o.provides.build: src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/UUV6DOF.cpp.o


# Object files for target UUV6DOF_plugin
UUV6DOF_plugin_OBJECTS = \
"CMakeFiles/UUV6DOF_plugin.dir/UUV6DOF.cpp.o"

# External object files for target UUV6DOF_plugin
UUV6DOF_plugin_EXTERNAL_OBJECTS =

plugin_libs/libUUV6DOF_plugin.so.0.0.1: src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/UUV6DOF.cpp.o
plugin_libs/libUUV6DOF_plugin.so.0.0.1: src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/build.make
plugin_libs/libUUV6DOF_plugin.so.0.0.1: src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lbrown62/scrimmage/scrimmage/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../../../plugin_libs/libUUV6DOF_plugin.so"
	cd /home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/motion/UUV6DOF && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UUV6DOF_plugin.dir/link.txt --verbose=$(VERBOSE)
	cd /home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/motion/UUV6DOF && $(CMAKE_COMMAND) -E cmake_symlink_library ../../../../plugin_libs/libUUV6DOF_plugin.so.0.0.1 ../../../../plugin_libs/libUUV6DOF_plugin.so.0 ../../../../plugin_libs/libUUV6DOF_plugin.so

plugin_libs/libUUV6DOF_plugin.so.0: plugin_libs/libUUV6DOF_plugin.so.0.0.1
	@$(CMAKE_COMMAND) -E touch_nocreate plugin_libs/libUUV6DOF_plugin.so.0

plugin_libs/libUUV6DOF_plugin.so: plugin_libs/libUUV6DOF_plugin.so.0.0.1
	@$(CMAKE_COMMAND) -E touch_nocreate plugin_libs/libUUV6DOF_plugin.so

# Rule to build all files generated by this target.
src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/build: plugin_libs/libUUV6DOF_plugin.so

.PHONY : src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/build

src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/requires: src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/UUV6DOF.cpp.o.requires

.PHONY : src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/requires

src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/clean:
	cd /home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/motion/UUV6DOF && $(CMAKE_COMMAND) -P CMakeFiles/UUV6DOF_plugin.dir/cmake_clean.cmake
.PHONY : src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/clean

src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/depend:
	cd /home/lbrown62/scrimmage/scrimmage/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lbrown62/scrimmage/scrimmage /home/lbrown62/scrimmage/scrimmage/src/plugins/motion/UUV6DOF /home/lbrown62/scrimmage/scrimmage/cmake-build-debug /home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/motion/UUV6DOF /home/lbrown62/scrimmage/scrimmage/cmake-build-debug/src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/plugins/motion/UUV6DOF/CMakeFiles/UUV6DOF_plugin.dir/depend

