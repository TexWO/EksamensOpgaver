# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\simon\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\simon\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\simon\C-projects\EksamensOpgaver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\simon\C-projects\EksamensOpgaver\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Eksamensopgaver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Eksamensopgaver.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Eksamensopgaver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Eksamensopgaver.dir/flags.make

CMakeFiles/Eksamensopgaver.dir/Yatzy/main.c.obj: CMakeFiles/Eksamensopgaver.dir/flags.make
CMakeFiles/Eksamensopgaver.dir/Yatzy/main.c.obj: C:/Users/simon/C-projects/EksamensOpgaver/Yatzy/main.c
CMakeFiles/Eksamensopgaver.dir/Yatzy/main.c.obj: CMakeFiles/Eksamensopgaver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\simon\C-projects\EksamensOpgaver\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Eksamensopgaver.dir/Yatzy/main.c.obj"
	C:\Users\simon\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Eksamensopgaver.dir/Yatzy/main.c.obj -MF CMakeFiles\Eksamensopgaver.dir\Yatzy\main.c.obj.d -o CMakeFiles\Eksamensopgaver.dir\Yatzy\main.c.obj -c C:\Users\simon\C-projects\EksamensOpgaver\Yatzy\main.c

CMakeFiles/Eksamensopgaver.dir/Yatzy/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Eksamensopgaver.dir/Yatzy/main.c.i"
	C:\Users\simon\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\simon\C-projects\EksamensOpgaver\Yatzy\main.c > CMakeFiles\Eksamensopgaver.dir\Yatzy\main.c.i

CMakeFiles/Eksamensopgaver.dir/Yatzy/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Eksamensopgaver.dir/Yatzy/main.c.s"
	C:\Users\simon\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\simon\C-projects\EksamensOpgaver\Yatzy\main.c -o CMakeFiles\Eksamensopgaver.dir\Yatzy\main.c.s

# Object files for target Eksamensopgaver
Eksamensopgaver_OBJECTS = \
"CMakeFiles/Eksamensopgaver.dir/Yatzy/main.c.obj"

# External object files for target Eksamensopgaver
Eksamensopgaver_EXTERNAL_OBJECTS =

Eksamensopgaver.exe: CMakeFiles/Eksamensopgaver.dir/Yatzy/main.c.obj
Eksamensopgaver.exe: CMakeFiles/Eksamensopgaver.dir/build.make
Eksamensopgaver.exe: CMakeFiles/Eksamensopgaver.dir/linkLibs.rsp
Eksamensopgaver.exe: CMakeFiles/Eksamensopgaver.dir/objects1.rsp
Eksamensopgaver.exe: CMakeFiles/Eksamensopgaver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\simon\C-projects\EksamensOpgaver\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Eksamensopgaver.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Eksamensopgaver.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Eksamensopgaver.dir/build: Eksamensopgaver.exe
.PHONY : CMakeFiles/Eksamensopgaver.dir/build

CMakeFiles/Eksamensopgaver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Eksamensopgaver.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Eksamensopgaver.dir/clean

CMakeFiles/Eksamensopgaver.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\simon\C-projects\EksamensOpgaver C:\Users\simon\C-projects\EksamensOpgaver C:\Users\simon\C-projects\EksamensOpgaver\cmake-build-debug C:\Users\simon\C-projects\EksamensOpgaver\cmake-build-debug C:\Users\simon\C-projects\EksamensOpgaver\cmake-build-debug\CMakeFiles\Eksamensopgaver.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Eksamensopgaver.dir/depend

