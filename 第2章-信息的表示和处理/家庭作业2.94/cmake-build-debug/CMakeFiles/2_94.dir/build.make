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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/lee/Desktop/Computer systems_A Programmer's Perspective/第2章-信息的表示和处理/家庭作业2.94"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/lee/Desktop/Computer systems_A Programmer's Perspective/第2章-信息的表示和处理/家庭作业2.94/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/2_94.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2_94.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2_94.dir/flags.make

CMakeFiles/2_94.dir/main.c.o: CMakeFiles/2_94.dir/flags.make
CMakeFiles/2_94.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/lee/Desktop/Computer systems_A Programmer's Perspective/第2章-信息的表示和处理/家庭作业2.94/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/2_94.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/2_94.dir/main.c.o   -c "/Users/lee/Desktop/Computer systems_A Programmer's Perspective/第2章-信息的表示和处理/家庭作业2.94/main.c"

CMakeFiles/2_94.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/2_94.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/lee/Desktop/Computer systems_A Programmer's Perspective/第2章-信息的表示和处理/家庭作业2.94/main.c" > CMakeFiles/2_94.dir/main.c.i

CMakeFiles/2_94.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/2_94.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/lee/Desktop/Computer systems_A Programmer's Perspective/第2章-信息的表示和处理/家庭作业2.94/main.c" -o CMakeFiles/2_94.dir/main.c.s

CMakeFiles/2_94.dir/main.c.o.requires:

.PHONY : CMakeFiles/2_94.dir/main.c.o.requires

CMakeFiles/2_94.dir/main.c.o.provides: CMakeFiles/2_94.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/2_94.dir/build.make CMakeFiles/2_94.dir/main.c.o.provides.build
.PHONY : CMakeFiles/2_94.dir/main.c.o.provides

CMakeFiles/2_94.dir/main.c.o.provides.build: CMakeFiles/2_94.dir/main.c.o


# Object files for target 2_94
2_94_OBJECTS = \
"CMakeFiles/2_94.dir/main.c.o"

# External object files for target 2_94
2_94_EXTERNAL_OBJECTS =

2_94: CMakeFiles/2_94.dir/main.c.o
2_94: CMakeFiles/2_94.dir/build.make
2_94: CMakeFiles/2_94.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/lee/Desktop/Computer systems_A Programmer's Perspective/第2章-信息的表示和处理/家庭作业2.94/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 2_94"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/2_94.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2_94.dir/build: 2_94

.PHONY : CMakeFiles/2_94.dir/build

CMakeFiles/2_94.dir/requires: CMakeFiles/2_94.dir/main.c.o.requires

.PHONY : CMakeFiles/2_94.dir/requires

CMakeFiles/2_94.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/2_94.dir/cmake_clean.cmake
.PHONY : CMakeFiles/2_94.dir/clean

CMakeFiles/2_94.dir/depend:
	cd "/Users/lee/Desktop/Computer systems_A Programmer's Perspective/第2章-信息的表示和处理/家庭作业2.94/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/lee/Desktop/Computer systems_A Programmer's Perspective/第2章-信息的表示和处理/家庭作业2.94" "/Users/lee/Desktop/Computer systems_A Programmer's Perspective/第2章-信息的表示和处理/家庭作业2.94" "/Users/lee/Desktop/Computer systems_A Programmer's Perspective/第2章-信息的表示和处理/家庭作业2.94/cmake-build-debug" "/Users/lee/Desktop/Computer systems_A Programmer's Perspective/第2章-信息的表示和处理/家庭作业2.94/cmake-build-debug" "/Users/lee/Desktop/Computer systems_A Programmer's Perspective/第2章-信息的表示和处理/家庭作业2.94/cmake-build-debug/CMakeFiles/2_94.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/2_94.dir/depend

