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
CMAKE_SOURCE_DIR = /home/lsh/NFC_READ

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lsh/NFC_READ

# Include any dependencies generated for this target.
include nfc/CMakeFiles/time_stamp.dir/depend.make

# Include the progress variables for this target.
include nfc/CMakeFiles/time_stamp.dir/progress.make

# Include the compile flags for this target's objects.
include nfc/CMakeFiles/time_stamp.dir/flags.make

nfc/CMakeFiles/time_stamp.dir/time_stamp/time_stamp.c.o: nfc/CMakeFiles/time_stamp.dir/flags.make
nfc/CMakeFiles/time_stamp.dir/time_stamp/time_stamp.c.o: nfc/time_stamp/time_stamp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lsh/NFC_READ/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object nfc/CMakeFiles/time_stamp.dir/time_stamp/time_stamp.c.o"
	cd /home/lsh/NFC_READ/nfc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/time_stamp.dir/time_stamp/time_stamp.c.o   -c /home/lsh/NFC_READ/nfc/time_stamp/time_stamp.c

nfc/CMakeFiles/time_stamp.dir/time_stamp/time_stamp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/time_stamp.dir/time_stamp/time_stamp.c.i"
	cd /home/lsh/NFC_READ/nfc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lsh/NFC_READ/nfc/time_stamp/time_stamp.c > CMakeFiles/time_stamp.dir/time_stamp/time_stamp.c.i

nfc/CMakeFiles/time_stamp.dir/time_stamp/time_stamp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/time_stamp.dir/time_stamp/time_stamp.c.s"
	cd /home/lsh/NFC_READ/nfc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lsh/NFC_READ/nfc/time_stamp/time_stamp.c -o CMakeFiles/time_stamp.dir/time_stamp/time_stamp.c.s

# Object files for target time_stamp
time_stamp_OBJECTS = \
"CMakeFiles/time_stamp.dir/time_stamp/time_stamp.c.o"

# External object files for target time_stamp
time_stamp_EXTERNAL_OBJECTS =

nfc/libtime_stamp.a: nfc/CMakeFiles/time_stamp.dir/time_stamp/time_stamp.c.o
nfc/libtime_stamp.a: nfc/CMakeFiles/time_stamp.dir/build.make
nfc/libtime_stamp.a: nfc/CMakeFiles/time_stamp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lsh/NFC_READ/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libtime_stamp.a"
	cd /home/lsh/NFC_READ/nfc && $(CMAKE_COMMAND) -P CMakeFiles/time_stamp.dir/cmake_clean_target.cmake
	cd /home/lsh/NFC_READ/nfc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/time_stamp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
nfc/CMakeFiles/time_stamp.dir/build: nfc/libtime_stamp.a

.PHONY : nfc/CMakeFiles/time_stamp.dir/build

nfc/CMakeFiles/time_stamp.dir/clean:
	cd /home/lsh/NFC_READ/nfc && $(CMAKE_COMMAND) -P CMakeFiles/time_stamp.dir/cmake_clean.cmake
.PHONY : nfc/CMakeFiles/time_stamp.dir/clean

nfc/CMakeFiles/time_stamp.dir/depend:
	cd /home/lsh/NFC_READ && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lsh/NFC_READ /home/lsh/NFC_READ/nfc /home/lsh/NFC_READ /home/lsh/NFC_READ/nfc /home/lsh/NFC_READ/nfc/CMakeFiles/time_stamp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : nfc/CMakeFiles/time_stamp.dir/depend
