# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow/zawawa

# Include any dependencies generated for this target.
include CMakeFiles/zad1Fraction.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/zad1Fraction.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/zad1Fraction.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zad1Fraction.dir/flags.make

CMakeFiles/zad1Fraction.dir/fraction.cpp.o: CMakeFiles/zad1Fraction.dir/flags.make
CMakeFiles/zad1Fraction.dir/fraction.cpp.o: ../fraction.cpp
CMakeFiles/zad1Fraction.dir/fraction.cpp.o: CMakeFiles/zad1Fraction.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow/zawawa/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zad1Fraction.dir/fraction.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zad1Fraction.dir/fraction.cpp.o -MF CMakeFiles/zad1Fraction.dir/fraction.cpp.o.d -o CMakeFiles/zad1Fraction.dir/fraction.cpp.o -c /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow/fraction.cpp

CMakeFiles/zad1Fraction.dir/fraction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zad1Fraction.dir/fraction.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow/fraction.cpp > CMakeFiles/zad1Fraction.dir/fraction.cpp.i

CMakeFiles/zad1Fraction.dir/fraction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zad1Fraction.dir/fraction.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow/fraction.cpp -o CMakeFiles/zad1Fraction.dir/fraction.cpp.s

CMakeFiles/zad1Fraction.dir/main.cpp.o: CMakeFiles/zad1Fraction.dir/flags.make
CMakeFiles/zad1Fraction.dir/main.cpp.o: ../main.cpp
CMakeFiles/zad1Fraction.dir/main.cpp.o: CMakeFiles/zad1Fraction.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow/zawawa/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/zad1Fraction.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zad1Fraction.dir/main.cpp.o -MF CMakeFiles/zad1Fraction.dir/main.cpp.o.d -o CMakeFiles/zad1Fraction.dir/main.cpp.o -c /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow/main.cpp

CMakeFiles/zad1Fraction.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zad1Fraction.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow/main.cpp > CMakeFiles/zad1Fraction.dir/main.cpp.i

CMakeFiles/zad1Fraction.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zad1Fraction.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow/main.cpp -o CMakeFiles/zad1Fraction.dir/main.cpp.s

# Object files for target zad1Fraction
zad1Fraction_OBJECTS = \
"CMakeFiles/zad1Fraction.dir/fraction.cpp.o" \
"CMakeFiles/zad1Fraction.dir/main.cpp.o"

# External object files for target zad1Fraction
zad1Fraction_EXTERNAL_OBJECTS =

bin/zad1Fraction: CMakeFiles/zad1Fraction.dir/fraction.cpp.o
bin/zad1Fraction: CMakeFiles/zad1Fraction.dir/main.cpp.o
bin/zad1Fraction: CMakeFiles/zad1Fraction.dir/build.make
bin/zad1Fraction: CMakeFiles/zad1Fraction.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow/zawawa/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable bin/zad1Fraction"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zad1Fraction.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zad1Fraction.dir/build: bin/zad1Fraction
.PHONY : CMakeFiles/zad1Fraction.dir/build

CMakeFiles/zad1Fraction.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zad1Fraction.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zad1Fraction.dir/clean

CMakeFiles/zad1Fraction.dir/depend:
	cd /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow/zawawa && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow/zawawa /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow/zawawa /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow/zawawa/CMakeFiles/zad1Fraction.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zad1Fraction.dir/depend

