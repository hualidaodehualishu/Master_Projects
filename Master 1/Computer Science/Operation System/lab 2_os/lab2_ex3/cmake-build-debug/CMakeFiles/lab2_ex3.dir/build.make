# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zhouxuan/Desktop/lab2_XuanZHOU/lab2_ex3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zhouxuan/Desktop/lab2_XuanZHOU/lab2_ex3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab2_ex3.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/lab2_ex3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab2_ex3.dir/flags.make

CMakeFiles/lab2_ex3.dir/main.c.o: CMakeFiles/lab2_ex3.dir/flags.make
CMakeFiles/lab2_ex3.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhouxuan/Desktop/lab2_XuanZHOU/lab2_ex3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab2_ex3.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab2_ex3.dir/main.c.o -c /Users/zhouxuan/Desktop/lab2_XuanZHOU/lab2_ex3/main.c

CMakeFiles/lab2_ex3.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab2_ex3.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/zhouxuan/Desktop/lab2_XuanZHOU/lab2_ex3/main.c > CMakeFiles/lab2_ex3.dir/main.c.i

CMakeFiles/lab2_ex3.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab2_ex3.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/zhouxuan/Desktop/lab2_XuanZHOU/lab2_ex3/main.c -o CMakeFiles/lab2_ex3.dir/main.c.s

# Object files for target lab2_ex3
lab2_ex3_OBJECTS = \
"CMakeFiles/lab2_ex3.dir/main.c.o"

# External object files for target lab2_ex3
lab2_ex3_EXTERNAL_OBJECTS =

lab2_ex3: CMakeFiles/lab2_ex3.dir/main.c.o
lab2_ex3: CMakeFiles/lab2_ex3.dir/build.make
lab2_ex3: CMakeFiles/lab2_ex3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhouxuan/Desktop/lab2_XuanZHOU/lab2_ex3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable lab2_ex3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab2_ex3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab2_ex3.dir/build: lab2_ex3
.PHONY : CMakeFiles/lab2_ex3.dir/build

CMakeFiles/lab2_ex3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab2_ex3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab2_ex3.dir/clean

CMakeFiles/lab2_ex3.dir/depend:
	cd /Users/zhouxuan/Desktop/lab2_XuanZHOU/lab2_ex3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhouxuan/Desktop/lab2_XuanZHOU/lab2_ex3 /Users/zhouxuan/Desktop/lab2_XuanZHOU/lab2_ex3 /Users/zhouxuan/Desktop/lab2_XuanZHOU/lab2_ex3/cmake-build-debug /Users/zhouxuan/Desktop/lab2_XuanZHOU/lab2_ex3/cmake-build-debug /Users/zhouxuan/Desktop/lab2_XuanZHOU/lab2_ex3/cmake-build-debug/CMakeFiles/lab2_ex3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab2_ex3.dir/depend

