# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\voice\Documents\CS211\final_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\voice\Documents\CS211\final_project\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Squingo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Squingo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Squingo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Squingo.dir/flags.make

CMakeFiles/Squingo.dir/src/character.cxx.obj: CMakeFiles/Squingo.dir/flags.make
CMakeFiles/Squingo.dir/src/character.cxx.obj: CMakeFiles/Squingo.dir/includes_CXX.rsp
CMakeFiles/Squingo.dir/src/character.cxx.obj: ../src/character.cxx
CMakeFiles/Squingo.dir/src/character.cxx.obj: CMakeFiles/Squingo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\voice\Documents\CS211\final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Squingo.dir/src/character.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Squingo.dir/src/character.cxx.obj -MF CMakeFiles\Squingo.dir\src\character.cxx.obj.d -o CMakeFiles\Squingo.dir\src\character.cxx.obj -c C:\Users\voice\Documents\CS211\final_project\src\character.cxx

CMakeFiles/Squingo.dir/src/character.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Squingo.dir/src/character.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\voice\Documents\CS211\final_project\src\character.cxx > CMakeFiles\Squingo.dir\src\character.cxx.i

CMakeFiles/Squingo.dir/src/character.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Squingo.dir/src/character.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\voice\Documents\CS211\final_project\src\character.cxx -o CMakeFiles\Squingo.dir\src\character.cxx.s

CMakeFiles/Squingo.dir/src/object.cxx.obj: CMakeFiles/Squingo.dir/flags.make
CMakeFiles/Squingo.dir/src/object.cxx.obj: CMakeFiles/Squingo.dir/includes_CXX.rsp
CMakeFiles/Squingo.dir/src/object.cxx.obj: ../src/object.cxx
CMakeFiles/Squingo.dir/src/object.cxx.obj: CMakeFiles/Squingo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\voice\Documents\CS211\final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Squingo.dir/src/object.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Squingo.dir/src/object.cxx.obj -MF CMakeFiles\Squingo.dir\src\object.cxx.obj.d -o CMakeFiles\Squingo.dir\src\object.cxx.obj -c C:\Users\voice\Documents\CS211\final_project\src\object.cxx

CMakeFiles/Squingo.dir/src/object.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Squingo.dir/src/object.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\voice\Documents\CS211\final_project\src\object.cxx > CMakeFiles\Squingo.dir\src\object.cxx.i

CMakeFiles/Squingo.dir/src/object.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Squingo.dir/src/object.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\voice\Documents\CS211\final_project\src\object.cxx -o CMakeFiles\Squingo.dir\src\object.cxx.s

CMakeFiles/Squingo.dir/src/model.cxx.obj: CMakeFiles/Squingo.dir/flags.make
CMakeFiles/Squingo.dir/src/model.cxx.obj: CMakeFiles/Squingo.dir/includes_CXX.rsp
CMakeFiles/Squingo.dir/src/model.cxx.obj: ../src/model.cxx
CMakeFiles/Squingo.dir/src/model.cxx.obj: CMakeFiles/Squingo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\voice\Documents\CS211\final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Squingo.dir/src/model.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Squingo.dir/src/model.cxx.obj -MF CMakeFiles\Squingo.dir\src\model.cxx.obj.d -o CMakeFiles\Squingo.dir\src\model.cxx.obj -c C:\Users\voice\Documents\CS211\final_project\src\model.cxx

CMakeFiles/Squingo.dir/src/model.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Squingo.dir/src/model.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\voice\Documents\CS211\final_project\src\model.cxx > CMakeFiles\Squingo.dir\src\model.cxx.i

CMakeFiles/Squingo.dir/src/model.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Squingo.dir/src/model.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\voice\Documents\CS211\final_project\src\model.cxx -o CMakeFiles\Squingo.dir\src\model.cxx.s

CMakeFiles/Squingo.dir/src/view.cxx.obj: CMakeFiles/Squingo.dir/flags.make
CMakeFiles/Squingo.dir/src/view.cxx.obj: CMakeFiles/Squingo.dir/includes_CXX.rsp
CMakeFiles/Squingo.dir/src/view.cxx.obj: ../src/view.cxx
CMakeFiles/Squingo.dir/src/view.cxx.obj: CMakeFiles/Squingo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\voice\Documents\CS211\final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Squingo.dir/src/view.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Squingo.dir/src/view.cxx.obj -MF CMakeFiles\Squingo.dir\src\view.cxx.obj.d -o CMakeFiles\Squingo.dir\src\view.cxx.obj -c C:\Users\voice\Documents\CS211\final_project\src\view.cxx

CMakeFiles/Squingo.dir/src/view.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Squingo.dir/src/view.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\voice\Documents\CS211\final_project\src\view.cxx > CMakeFiles\Squingo.dir\src\view.cxx.i

CMakeFiles/Squingo.dir/src/view.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Squingo.dir/src/view.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\voice\Documents\CS211\final_project\src\view.cxx -o CMakeFiles\Squingo.dir\src\view.cxx.s

CMakeFiles/Squingo.dir/src/controller.cxx.obj: CMakeFiles/Squingo.dir/flags.make
CMakeFiles/Squingo.dir/src/controller.cxx.obj: CMakeFiles/Squingo.dir/includes_CXX.rsp
CMakeFiles/Squingo.dir/src/controller.cxx.obj: ../src/controller.cxx
CMakeFiles/Squingo.dir/src/controller.cxx.obj: CMakeFiles/Squingo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\voice\Documents\CS211\final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Squingo.dir/src/controller.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Squingo.dir/src/controller.cxx.obj -MF CMakeFiles\Squingo.dir\src\controller.cxx.obj.d -o CMakeFiles\Squingo.dir\src\controller.cxx.obj -c C:\Users\voice\Documents\CS211\final_project\src\controller.cxx

CMakeFiles/Squingo.dir/src/controller.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Squingo.dir/src/controller.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\voice\Documents\CS211\final_project\src\controller.cxx > CMakeFiles\Squingo.dir\src\controller.cxx.i

CMakeFiles/Squingo.dir/src/controller.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Squingo.dir/src/controller.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\voice\Documents\CS211\final_project\src\controller.cxx -o CMakeFiles\Squingo.dir\src\controller.cxx.s

CMakeFiles/Squingo.dir/src/squingo.cxx.obj: CMakeFiles/Squingo.dir/flags.make
CMakeFiles/Squingo.dir/src/squingo.cxx.obj: CMakeFiles/Squingo.dir/includes_CXX.rsp
CMakeFiles/Squingo.dir/src/squingo.cxx.obj: ../src/squingo.cxx
CMakeFiles/Squingo.dir/src/squingo.cxx.obj: CMakeFiles/Squingo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\voice\Documents\CS211\final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Squingo.dir/src/squingo.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Squingo.dir/src/squingo.cxx.obj -MF CMakeFiles\Squingo.dir\src\squingo.cxx.obj.d -o CMakeFiles\Squingo.dir\src\squingo.cxx.obj -c C:\Users\voice\Documents\CS211\final_project\src\squingo.cxx

CMakeFiles/Squingo.dir/src/squingo.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Squingo.dir/src/squingo.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\voice\Documents\CS211\final_project\src\squingo.cxx > CMakeFiles\Squingo.dir\src\squingo.cxx.i

CMakeFiles/Squingo.dir/src/squingo.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Squingo.dir/src/squingo.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\voice\Documents\CS211\final_project\src\squingo.cxx -o CMakeFiles\Squingo.dir\src\squingo.cxx.s

# Object files for target Squingo
Squingo_OBJECTS = \
"CMakeFiles/Squingo.dir/src/character.cxx.obj" \
"CMakeFiles/Squingo.dir/src/object.cxx.obj" \
"CMakeFiles/Squingo.dir/src/model.cxx.obj" \
"CMakeFiles/Squingo.dir/src/view.cxx.obj" \
"CMakeFiles/Squingo.dir/src/controller.cxx.obj" \
"CMakeFiles/Squingo.dir/src/squingo.cxx.obj"

# External object files for target Squingo
Squingo_EXTERNAL_OBJECTS =

Squingo.exe: CMakeFiles/Squingo.dir/src/character.cxx.obj
Squingo.exe: CMakeFiles/Squingo.dir/src/object.cxx.obj
Squingo.exe: CMakeFiles/Squingo.dir/src/model.cxx.obj
Squingo.exe: CMakeFiles/Squingo.dir/src/view.cxx.obj
Squingo.exe: CMakeFiles/Squingo.dir/src/controller.cxx.obj
Squingo.exe: CMakeFiles/Squingo.dir/src/squingo.cxx.obj
Squingo.exe: CMakeFiles/Squingo.dir/build.make
Squingo.exe: .cs211/lib/ge211/src/libge211.a
Squingo.exe: C:/MinGW/lib/libSDL2.dll.a
Squingo.exe: C:/MinGW/lib/libSDL2_image.dll.a
Squingo.exe: C:/MinGW/lib/libSDL2_mixer.dll.a
Squingo.exe: C:/MinGW/lib/libSDL2_ttf.dll.a
Squingo.exe: CMakeFiles/Squingo.dir/linklibs.rsp
Squingo.exe: CMakeFiles/Squingo.dir/objects1.rsp
Squingo.exe: CMakeFiles/Squingo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\voice\Documents\CS211\final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Squingo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Squingo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Squingo.dir/build: Squingo.exe
.PHONY : CMakeFiles/Squingo.dir/build

CMakeFiles/Squingo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Squingo.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Squingo.dir/clean

CMakeFiles/Squingo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\voice\Documents\CS211\final_project C:\Users\voice\Documents\CS211\final_project C:\Users\voice\Documents\CS211\final_project\cmake-build-debug C:\Users\voice\Documents\CS211\final_project\cmake-build-debug C:\Users\voice\Documents\CS211\final_project\cmake-build-debug\CMakeFiles\Squingo.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Squingo.dir/depend
