# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /usr/src/app

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /usr/src/app/build_dc

# Include any dependencies generated for this target.
include CMakeFiles/mapper_reducer_prg.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mapper_reducer_prg.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mapper_reducer_prg.dir/flags.make

CMakeFiles/mapper_reducer_prg.dir/average/mapper.cpp.o: CMakeFiles/mapper_reducer_prg.dir/flags.make
CMakeFiles/mapper_reducer_prg.dir/average/mapper.cpp.o: ../average/mapper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/src/app/build_dc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mapper_reducer_prg.dir/average/mapper.cpp.o"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mapper_reducer_prg.dir/average/mapper.cpp.o -c /usr/src/app/average/mapper.cpp

CMakeFiles/mapper_reducer_prg.dir/average/mapper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mapper_reducer_prg.dir/average/mapper.cpp.i"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/src/app/average/mapper.cpp > CMakeFiles/mapper_reducer_prg.dir/average/mapper.cpp.i

CMakeFiles/mapper_reducer_prg.dir/average/mapper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mapper_reducer_prg.dir/average/mapper.cpp.s"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/src/app/average/mapper.cpp -o CMakeFiles/mapper_reducer_prg.dir/average/mapper.cpp.s

# Object files for target mapper_reducer_prg
mapper_reducer_prg_OBJECTS = \
"CMakeFiles/mapper_reducer_prg.dir/average/mapper.cpp.o"

# External object files for target mapper_reducer_prg
mapper_reducer_prg_EXTERNAL_OBJECTS =

lib/libmapper_reducer_prg.a: CMakeFiles/mapper_reducer_prg.dir/average/mapper.cpp.o
lib/libmapper_reducer_prg.a: CMakeFiles/mapper_reducer_prg.dir/build.make
lib/libmapper_reducer_prg.a: CMakeFiles/mapper_reducer_prg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/usr/src/app/build_dc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library lib/libmapper_reducer_prg.a"
	$(CMAKE_COMMAND) -P CMakeFiles/mapper_reducer_prg.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mapper_reducer_prg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mapper_reducer_prg.dir/build: lib/libmapper_reducer_prg.a

.PHONY : CMakeFiles/mapper_reducer_prg.dir/build

CMakeFiles/mapper_reducer_prg.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mapper_reducer_prg.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mapper_reducer_prg.dir/clean

CMakeFiles/mapper_reducer_prg.dir/depend:
	cd /usr/src/app/build_dc && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /usr/src/app /usr/src/app /usr/src/app/build_dc /usr/src/app/build_dc /usr/src/app/build_dc/CMakeFiles/mapper_reducer_prg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mapper_reducer_prg.dir/depend

