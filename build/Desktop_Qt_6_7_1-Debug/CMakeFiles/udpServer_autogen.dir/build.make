# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/udpServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/udpServer/build/Desktop_Qt_6_7_1-Debug

# Utility rule file for udpServer_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/udpServer_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/udpServer_autogen.dir/progress.make

CMakeFiles/udpServer_autogen: udpServer_autogen/timestamp

udpServer_autogen/timestamp: /opt/Qt/6.7.1/gcc_64/./libexec/moc
udpServer_autogen/timestamp: CMakeFiles/udpServer_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/root/udpServer/build/Desktop_Qt_6_7_1-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target udpServer"
	/usr/bin/cmake -E cmake_autogen /root/udpServer/build/Desktop_Qt_6_7_1-Debug/CMakeFiles/udpServer_autogen.dir/AutogenInfo.json Debug
	/usr/bin/cmake -E touch /root/udpServer/build/Desktop_Qt_6_7_1-Debug/udpServer_autogen/timestamp

udpServer_autogen: CMakeFiles/udpServer_autogen
udpServer_autogen: udpServer_autogen/timestamp
udpServer_autogen: CMakeFiles/udpServer_autogen.dir/build.make
.PHONY : udpServer_autogen

# Rule to build all files generated by this target.
CMakeFiles/udpServer_autogen.dir/build: udpServer_autogen
.PHONY : CMakeFiles/udpServer_autogen.dir/build

CMakeFiles/udpServer_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/udpServer_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/udpServer_autogen.dir/clean

CMakeFiles/udpServer_autogen.dir/depend:
	cd /root/udpServer/build/Desktop_Qt_6_7_1-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/udpServer /root/udpServer /root/udpServer/build/Desktop_Qt_6_7_1-Debug /root/udpServer/build/Desktop_Qt_6_7_1-Debug /root/udpServer/build/Desktop_Qt_6_7_1-Debug/CMakeFiles/udpServer_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/udpServer_autogen.dir/depend
