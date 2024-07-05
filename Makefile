# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = //home/MK/Documents/git

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = //home/MK/Documents/git

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start //home/MK/Documents/git/CMakeFiles //home/MK/Documents/git//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start //home/MK/Documents/git/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Mittens

# Build rule for target.
Mittens: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Mittens
.PHONY : Mittens

# fast build rule for target.
Mittens/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Mittens.dir/build.make CMakeFiles/Mittens.dir/build
.PHONY : Mittens/fast

#=============================================================================
# Target rules for targets named zlib

# Build rule for target.
zlib: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 zlib
.PHONY : zlib

# fast build rule for target.
zlib/fast:
	$(MAKE) $(MAKESILENT) -f _deps/zlib-build/CMakeFiles/zlib.dir/build.make _deps/zlib-build/CMakeFiles/zlib.dir/build
.PHONY : zlib/fast

#=============================================================================
# Target rules for targets named curl_uninstall

# Build rule for target.
curl_uninstall: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 curl_uninstall
.PHONY : curl_uninstall

# fast build rule for target.
curl_uninstall/fast:
	$(MAKE) $(MAKESILENT) -f _deps/curl-build/CMakeFiles/curl_uninstall.dir/build.make _deps/curl-build/CMakeFiles/curl_uninstall.dir/build
.PHONY : curl_uninstall/fast

#=============================================================================
# Target rules for targets named curlu

# Build rule for target.
curlu: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 curlu
.PHONY : curlu

# fast build rule for target.
curlu/fast:
	$(MAKE) $(MAKESILENT) -f _deps/curl-build/lib/CMakeFiles/curlu.dir/build.make _deps/curl-build/lib/CMakeFiles/curlu.dir/build
.PHONY : curlu/fast

#=============================================================================
# Target rules for targets named libcurl_shared

# Build rule for target.
libcurl_shared: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 libcurl_shared
.PHONY : libcurl_shared

# fast build rule for target.
libcurl_shared/fast:
	$(MAKE) $(MAKESILENT) -f _deps/curl-build/lib/CMakeFiles/libcurl_shared.dir/build.make _deps/curl-build/lib/CMakeFiles/libcurl_shared.dir/build
.PHONY : libcurl_shared/fast

#=============================================================================
# Target rules for targets named cpr

# Build rule for target.
cpr: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 cpr
.PHONY : cpr

# fast build rule for target.
cpr/fast:
	$(MAKE) $(MAKESILENT) -f _deps/cpr-build/cpr/CMakeFiles/cpr.dir/build.make _deps/cpr-build/cpr/CMakeFiles/cpr.dir/build
.PHONY : cpr/fast

src/Player.o: src/Player.cpp.o
.PHONY : src/Player.o

# target to build an object file
src/Player.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Mittens.dir/build.make CMakeFiles/Mittens.dir/src/Player.cpp.o
.PHONY : src/Player.cpp.o

src/Player.i: src/Player.cpp.i
.PHONY : src/Player.i

# target to preprocess a source file
src/Player.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Mittens.dir/build.make CMakeFiles/Mittens.dir/src/Player.cpp.i
.PHONY : src/Player.cpp.i

src/Player.s: src/Player.cpp.s
.PHONY : src/Player.s

# target to generate assembly for a file
src/Player.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Mittens.dir/build.make CMakeFiles/Mittens.dir/src/Player.cpp.s
.PHONY : src/Player.cpp.s

src/RiotAPI.o: src/RiotAPI.cpp.o
.PHONY : src/RiotAPI.o

# target to build an object file
src/RiotAPI.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Mittens.dir/build.make CMakeFiles/Mittens.dir/src/RiotAPI.cpp.o
.PHONY : src/RiotAPI.cpp.o

src/RiotAPI.i: src/RiotAPI.cpp.i
.PHONY : src/RiotAPI.i

# target to preprocess a source file
src/RiotAPI.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Mittens.dir/build.make CMakeFiles/Mittens.dir/src/RiotAPI.cpp.i
.PHONY : src/RiotAPI.cpp.i

src/RiotAPI.s: src/RiotAPI.cpp.s
.PHONY : src/RiotAPI.s

# target to generate assembly for a file
src/RiotAPI.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Mittens.dir/build.make CMakeFiles/Mittens.dir/src/RiotAPI.cpp.s
.PHONY : src/RiotAPI.cpp.s

src/bot.o: src/bot.cpp.o
.PHONY : src/bot.o

# target to build an object file
src/bot.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Mittens.dir/build.make CMakeFiles/Mittens.dir/src/bot.cpp.o
.PHONY : src/bot.cpp.o

src/bot.i: src/bot.cpp.i
.PHONY : src/bot.i

# target to preprocess a source file
src/bot.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Mittens.dir/build.make CMakeFiles/Mittens.dir/src/bot.cpp.i
.PHONY : src/bot.cpp.i

src/bot.s: src/bot.cpp.s
.PHONY : src/bot.s

# target to generate assembly for a file
src/bot.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Mittens.dir/build.make CMakeFiles/Mittens.dir/src/bot.cpp.s
.PHONY : src/bot.cpp.s

src/data.o: src/data.cpp.o
.PHONY : src/data.o

# target to build an object file
src/data.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Mittens.dir/build.make CMakeFiles/Mittens.dir/src/data.cpp.o
.PHONY : src/data.cpp.o

src/data.i: src/data.cpp.i
.PHONY : src/data.i

# target to preprocess a source file
src/data.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Mittens.dir/build.make CMakeFiles/Mittens.dir/src/data.cpp.i
.PHONY : src/data.cpp.i

src/data.s: src/data.cpp.s
.PHONY : src/data.s

# target to generate assembly for a file
src/data.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Mittens.dir/build.make CMakeFiles/Mittens.dir/src/data.cpp.s
.PHONY : src/data.cpp.s

src/helpers.o: src/helpers.cpp.o
.PHONY : src/helpers.o

# target to build an object file
src/helpers.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Mittens.dir/build.make CMakeFiles/Mittens.dir/src/helpers.cpp.o
.PHONY : src/helpers.cpp.o

src/helpers.i: src/helpers.cpp.i
.PHONY : src/helpers.i

# target to preprocess a source file
src/helpers.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Mittens.dir/build.make CMakeFiles/Mittens.dir/src/helpers.cpp.i
.PHONY : src/helpers.cpp.i

src/helpers.s: src/helpers.cpp.s
.PHONY : src/helpers.s

# target to generate assembly for a file
src/helpers.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Mittens.dir/build.make CMakeFiles/Mittens.dir/src/helpers.cpp.s
.PHONY : src/helpers.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Mittens.dir/build.make CMakeFiles/Mittens.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Mittens.dir/build.make CMakeFiles/Mittens.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Mittens.dir/build.make CMakeFiles/Mittens.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/parsejson.o: src/parsejson.cpp.o
.PHONY : src/parsejson.o

# target to build an object file
src/parsejson.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Mittens.dir/build.make CMakeFiles/Mittens.dir/src/parsejson.cpp.o
.PHONY : src/parsejson.cpp.o

src/parsejson.i: src/parsejson.cpp.i
.PHONY : src/parsejson.i

# target to preprocess a source file
src/parsejson.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Mittens.dir/build.make CMakeFiles/Mittens.dir/src/parsejson.cpp.i
.PHONY : src/parsejson.cpp.i

src/parsejson.s: src/parsejson.cpp.s
.PHONY : src/parsejson.s

# target to generate assembly for a file
src/parsejson.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Mittens.dir/build.make CMakeFiles/Mittens.dir/src/parsejson.cpp.s
.PHONY : src/parsejson.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... curl_uninstall"
	@echo "... Mittens"
	@echo "... cpr"
	@echo "... curlu"
	@echo "... libcurl_shared"
	@echo "... zlib"
	@echo "... src/Player.o"
	@echo "... src/Player.i"
	@echo "... src/Player.s"
	@echo "... src/RiotAPI.o"
	@echo "... src/RiotAPI.i"
	@echo "... src/RiotAPI.s"
	@echo "... src/bot.o"
	@echo "... src/bot.i"
	@echo "... src/bot.s"
	@echo "... src/data.o"
	@echo "... src/data.i"
	@echo "... src/data.s"
	@echo "... src/helpers.o"
	@echo "... src/helpers.i"
	@echo "... src/helpers.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/parsejson.o"
	@echo "... src/parsejson.i"
	@echo "... src/parsejson.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

