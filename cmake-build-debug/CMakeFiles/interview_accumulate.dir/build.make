# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /cygdrive/c/Users/zyl/.CLion2019.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/zyl/.CLion2019.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/d/Program_Cpp/interview_accumulate

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/d/Program_Cpp/interview_accumulate/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/interview_accumulate.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/interview_accumulate.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/interview_accumulate.dir/flags.make

CMakeFiles/interview_accumulate.dir/main.cpp.o: CMakeFiles/interview_accumulate.dir/flags.make
CMakeFiles/interview_accumulate.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/Program_Cpp/interview_accumulate/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/interview_accumulate.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/interview_accumulate.dir/main.cpp.o -c /cygdrive/d/Program_Cpp/interview_accumulate/main.cpp

CMakeFiles/interview_accumulate.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interview_accumulate.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/Program_Cpp/interview_accumulate/main.cpp > CMakeFiles/interview_accumulate.dir/main.cpp.i

CMakeFiles/interview_accumulate.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interview_accumulate.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/Program_Cpp/interview_accumulate/main.cpp -o CMakeFiles/interview_accumulate.dir/main.cpp.s

CMakeFiles/interview_accumulate.dir/functions.cpp.o: CMakeFiles/interview_accumulate.dir/flags.make
CMakeFiles/interview_accumulate.dir/functions.cpp.o: ../functions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/Program_Cpp/interview_accumulate/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/interview_accumulate.dir/functions.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/interview_accumulate.dir/functions.cpp.o -c /cygdrive/d/Program_Cpp/interview_accumulate/functions.cpp

CMakeFiles/interview_accumulate.dir/functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interview_accumulate.dir/functions.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/Program_Cpp/interview_accumulate/functions.cpp > CMakeFiles/interview_accumulate.dir/functions.cpp.i

CMakeFiles/interview_accumulate.dir/functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interview_accumulate.dir/functions.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/Program_Cpp/interview_accumulate/functions.cpp -o CMakeFiles/interview_accumulate.dir/functions.cpp.s

# Object files for target interview_accumulate
interview_accumulate_OBJECTS = \
"CMakeFiles/interview_accumulate.dir/main.cpp.o" \
"CMakeFiles/interview_accumulate.dir/functions.cpp.o"

# External object files for target interview_accumulate
interview_accumulate_EXTERNAL_OBJECTS =

interview_accumulate.exe: CMakeFiles/interview_accumulate.dir/main.cpp.o
interview_accumulate.exe: CMakeFiles/interview_accumulate.dir/functions.cpp.o
interview_accumulate.exe: CMakeFiles/interview_accumulate.dir/build.make
interview_accumulate.exe: CMakeFiles/interview_accumulate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/d/Program_Cpp/interview_accumulate/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable interview_accumulate.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/interview_accumulate.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/interview_accumulate.dir/build: interview_accumulate.exe

.PHONY : CMakeFiles/interview_accumulate.dir/build

CMakeFiles/interview_accumulate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/interview_accumulate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/interview_accumulate.dir/clean

CMakeFiles/interview_accumulate.dir/depend:
	cd /cygdrive/d/Program_Cpp/interview_accumulate/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/d/Program_Cpp/interview_accumulate /cygdrive/d/Program_Cpp/interview_accumulate /cygdrive/d/Program_Cpp/interview_accumulate/cmake-build-debug /cygdrive/d/Program_Cpp/interview_accumulate/cmake-build-debug /cygdrive/d/Program_Cpp/interview_accumulate/cmake-build-debug/CMakeFiles/interview_accumulate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/interview_accumulate.dir/depend

