# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.26.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.26.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/manon/Documents/UCL/bac_3/Q6/elements finis/projet/group093-mkummeler-clefebvre"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/manon/Documents/UCL/bac_3/Q6/elements finis/projet/group093-mkummeler-clefebvre/build"

# Include any dependencies generated for this target.
include CMakeFiles/executable_main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/executable_main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/executable_main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/executable_main.dir/flags.make

CMakeFiles/executable_main.dir/src/main.c.o: CMakeFiles/executable_main.dir/flags.make
CMakeFiles/executable_main.dir/src/main.c.o: /Users/manon/Documents/UCL/bac_3/Q6/elements\ finis/projet/group093-mkummeler-clefebvre/src/main.c
CMakeFiles/executable_main.dir/src/main.c.o: CMakeFiles/executable_main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/manon/Documents/UCL/bac_3/Q6/elements finis/projet/group093-mkummeler-clefebvre/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/executable_main.dir/src/main.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/executable_main.dir/src/main.c.o -MF CMakeFiles/executable_main.dir/src/main.c.o.d -o CMakeFiles/executable_main.dir/src/main.c.o -c "/Users/manon/Documents/UCL/bac_3/Q6/elements finis/projet/group093-mkummeler-clefebvre/src/main.c"

CMakeFiles/executable_main.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/executable_main.dir/src/main.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/manon/Documents/UCL/bac_3/Q6/elements finis/projet/group093-mkummeler-clefebvre/src/main.c" > CMakeFiles/executable_main.dir/src/main.c.i

CMakeFiles/executable_main.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/executable_main.dir/src/main.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/manon/Documents/UCL/bac_3/Q6/elements finis/projet/group093-mkummeler-clefebvre/src/main.c" -o CMakeFiles/executable_main.dir/src/main.c.s

# Object files for target executable_main
executable_main_OBJECTS = \
"CMakeFiles/executable_main.dir/src/main.c.o"

# External object files for target executable_main
executable_main_EXTERNAL_OBJECTS =

executable_main: CMakeFiles/executable_main.dir/src/main.c.o
executable_main: CMakeFiles/executable_main.dir/build.make
executable_main: CMakeFiles/executable_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/manon/Documents/UCL/bac_3/Q6/elements finis/projet/group093-mkummeler-clefebvre/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable executable_main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/executable_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/executable_main.dir/build: executable_main
.PHONY : CMakeFiles/executable_main.dir/build

CMakeFiles/executable_main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/executable_main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/executable_main.dir/clean

CMakeFiles/executable_main.dir/depend:
	cd "/Users/manon/Documents/UCL/bac_3/Q6/elements finis/projet/group093-mkummeler-clefebvre/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/manon/Documents/UCL/bac_3/Q6/elements finis/projet/group093-mkummeler-clefebvre" "/Users/manon/Documents/UCL/bac_3/Q6/elements finis/projet/group093-mkummeler-clefebvre" "/Users/manon/Documents/UCL/bac_3/Q6/elements finis/projet/group093-mkummeler-clefebvre/build" "/Users/manon/Documents/UCL/bac_3/Q6/elements finis/projet/group093-mkummeler-clefebvre/build" "/Users/manon/Documents/UCL/bac_3/Q6/elements finis/projet/group093-mkummeler-clefebvre/build/CMakeFiles/executable_main.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/executable_main.dir/depend

