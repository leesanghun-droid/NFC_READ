# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lsh/SINVIHAM-MNTech/lsh/modbus/linux_modbus_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lsh/SINVIHAM-MNTech/lsh/modbus/linux_modbus_test

# Include any dependencies generated for this target.
include modbus/CMakeFiles/poll.dir/depend.make

# Include the progress variables for this target.
include modbus/CMakeFiles/poll.dir/progress.make

# Include the compile flags for this target's objects.
include modbus/CMakeFiles/poll.dir/flags.make

modbus/CMakeFiles/poll.dir/poll/poll.c.o: modbus/CMakeFiles/poll.dir/flags.make
modbus/CMakeFiles/poll.dir/poll/poll.c.o: modbus/poll/poll.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lsh/SINVIHAM-MNTech/lsh/modbus/linux_modbus_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object modbus/CMakeFiles/poll.dir/poll/poll.c.o"
	cd /home/lsh/SINVIHAM-MNTech/lsh/modbus/linux_modbus_test/modbus && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/poll.dir/poll/poll.c.o   -c /home/lsh/SINVIHAM-MNTech/lsh/modbus/linux_modbus_test/modbus/poll/poll.c

modbus/CMakeFiles/poll.dir/poll/poll.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/poll.dir/poll/poll.c.i"
	cd /home/lsh/SINVIHAM-MNTech/lsh/modbus/linux_modbus_test/modbus && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lsh/SINVIHAM-MNTech/lsh/modbus/linux_modbus_test/modbus/poll/poll.c > CMakeFiles/poll.dir/poll/poll.c.i

modbus/CMakeFiles/poll.dir/poll/poll.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/poll.dir/poll/poll.c.s"
	cd /home/lsh/SINVIHAM-MNTech/lsh/modbus/linux_modbus_test/modbus && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lsh/SINVIHAM-MNTech/lsh/modbus/linux_modbus_test/modbus/poll/poll.c -o CMakeFiles/poll.dir/poll/poll.c.s

# Object files for target poll
poll_OBJECTS = \
"CMakeFiles/poll.dir/poll/poll.c.o"

# External object files for target poll
poll_EXTERNAL_OBJECTS =

modbus/libpoll.a: modbus/CMakeFiles/poll.dir/poll/poll.c.o
modbus/libpoll.a: modbus/CMakeFiles/poll.dir/build.make
modbus/libpoll.a: modbus/CMakeFiles/poll.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lsh/SINVIHAM-MNTech/lsh/modbus/linux_modbus_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libpoll.a"
	cd /home/lsh/SINVIHAM-MNTech/lsh/modbus/linux_modbus_test/modbus && $(CMAKE_COMMAND) -P CMakeFiles/poll.dir/cmake_clean_target.cmake
	cd /home/lsh/SINVIHAM-MNTech/lsh/modbus/linux_modbus_test/modbus && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/poll.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
modbus/CMakeFiles/poll.dir/build: modbus/libpoll.a

.PHONY : modbus/CMakeFiles/poll.dir/build

modbus/CMakeFiles/poll.dir/clean:
	cd /home/lsh/SINVIHAM-MNTech/lsh/modbus/linux_modbus_test/modbus && $(CMAKE_COMMAND) -P CMakeFiles/poll.dir/cmake_clean.cmake
.PHONY : modbus/CMakeFiles/poll.dir/clean

modbus/CMakeFiles/poll.dir/depend:
	cd /home/lsh/SINVIHAM-MNTech/lsh/modbus/linux_modbus_test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lsh/SINVIHAM-MNTech/lsh/modbus/linux_modbus_test /home/lsh/SINVIHAM-MNTech/lsh/modbus/linux_modbus_test/modbus /home/lsh/SINVIHAM-MNTech/lsh/modbus/linux_modbus_test /home/lsh/SINVIHAM-MNTech/lsh/modbus/linux_modbus_test/modbus /home/lsh/SINVIHAM-MNTech/lsh/modbus/linux_modbus_test/modbus/CMakeFiles/poll.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modbus/CMakeFiles/poll.dir/depend

