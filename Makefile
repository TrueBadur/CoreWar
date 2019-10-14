# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /Users/wgorold/.brew/Cellar/cmake/3.15.4/bin/cmake

# The command to remove a file.
RM = /Users/wgorold/.brew/Cellar/cmake/3.15.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wgorold/d08_corewar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wgorold/d08_corewar

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/Users/wgorold/.brew/Cellar/cmake/3.15.4/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/Users/wgorold/.brew/Cellar/cmake/3.15.4/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/wgorold/d08_corewar/CMakeFiles /Users/wgorold/d08_corewar/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/wgorold/d08_corewar/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named asm

# Build rule for target.
asm: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 asm
.PHONY : asm

# fast build rule for target.
asm/fast:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/build
.PHONY : asm/fast

#=============================================================================
# Target rules for targets named corewar

# Build rule for target.
corewar: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 corewar
.PHONY : corewar

# fast build rule for target.
corewar/fast:
	$(MAKE) -f CMakeFiles/corewar.dir/build.make CMakeFiles/corewar.dir/build
.PHONY : corewar/fast

src/asm/assembler.o: src/asm/assembler.c.o

.PHONY : src/asm/assembler.o

# target to build an object file
src/asm/assembler.c.o:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/assembler.c.o
.PHONY : src/asm/assembler.c.o

src/asm/assembler.i: src/asm/assembler.c.i

.PHONY : src/asm/assembler.i

# target to preprocess a source file
src/asm/assembler.c.i:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/assembler.c.i
.PHONY : src/asm/assembler.c.i

src/asm/assembler.s: src/asm/assembler.c.s

.PHONY : src/asm/assembler.s

# target to generate assembly for a file
src/asm/assembler.c.s:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/assembler.c.s
.PHONY : src/asm/assembler.c.s

src/asm/champ_generator.o: src/asm/champ_generator.c.o

.PHONY : src/asm/champ_generator.o

# target to build an object file
src/asm/champ_generator.c.o:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/champ_generator.c.o
.PHONY : src/asm/champ_generator.c.o

src/asm/champ_generator.i: src/asm/champ_generator.c.i

.PHONY : src/asm/champ_generator.i

# target to preprocess a source file
src/asm/champ_generator.c.i:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/champ_generator.c.i
.PHONY : src/asm/champ_generator.c.i

src/asm/champ_generator.s: src/asm/champ_generator.c.s

.PHONY : src/asm/champ_generator.s

# target to generate assembly for a file
src/asm/champ_generator.c.s:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/champ_generator.c.s
.PHONY : src/asm/champ_generator.c.s

src/asm/cmdgen_funcs.o: src/asm/cmdgen_funcs.c.o

.PHONY : src/asm/cmdgen_funcs.o

# target to build an object file
src/asm/cmdgen_funcs.c.o:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/cmdgen_funcs.c.o
.PHONY : src/asm/cmdgen_funcs.c.o

src/asm/cmdgen_funcs.i: src/asm/cmdgen_funcs.c.i

.PHONY : src/asm/cmdgen_funcs.i

# target to preprocess a source file
src/asm/cmdgen_funcs.c.i:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/cmdgen_funcs.c.i
.PHONY : src/asm/cmdgen_funcs.c.i

src/asm/cmdgen_funcs.s: src/asm/cmdgen_funcs.c.s

.PHONY : src/asm/cmdgen_funcs.s

# target to generate assembly for a file
src/asm/cmdgen_funcs.c.s:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/cmdgen_funcs.c.s
.PHONY : src/asm/cmdgen_funcs.c.s

src/asm/disassembler.o: src/asm/disassembler.c.o

.PHONY : src/asm/disassembler.o

# target to build an object file
src/asm/disassembler.c.o:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/disassembler.c.o
.PHONY : src/asm/disassembler.c.o

src/asm/disassembler.i: src/asm/disassembler.c.i

.PHONY : src/asm/disassembler.i

# target to preprocess a source file
src/asm/disassembler.c.i:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/disassembler.c.i
.PHONY : src/asm/disassembler.c.i

src/asm/disassembler.s: src/asm/disassembler.c.s

.PHONY : src/asm/disassembler.s

# target to generate assembly for a file
src/asm/disassembler.c.s:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/disassembler.c.s
.PHONY : src/asm/disassembler.c.s

src/asm/lexer.o: src/asm/lexer.c.o

.PHONY : src/asm/lexer.o

# target to build an object file
src/asm/lexer.c.o:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/lexer.c.o
.PHONY : src/asm/lexer.c.o

src/asm/lexer.i: src/asm/lexer.c.i

.PHONY : src/asm/lexer.i

# target to preprocess a source file
src/asm/lexer.c.i:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/lexer.c.i
.PHONY : src/asm/lexer.c.i

src/asm/lexer.s: src/asm/lexer.c.s

.PHONY : src/asm/lexer.s

# target to generate assembly for a file
src/asm/lexer.c.s:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/lexer.c.s
.PHONY : src/asm/lexer.c.s

src/asm/main.o: src/asm/main.c.o

.PHONY : src/asm/main.o

# target to build an object file
src/asm/main.c.o:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/main.c.o
.PHONY : src/asm/main.c.o

src/asm/main.i: src/asm/main.c.i

.PHONY : src/asm/main.i

# target to preprocess a source file
src/asm/main.c.i:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/main.c.i
.PHONY : src/asm/main.c.i

src/asm/main.s: src/asm/main.c.s

.PHONY : src/asm/main.s

# target to generate assembly for a file
src/asm/main.c.s:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/main.c.s
.PHONY : src/asm/main.c.s

src/asm/main_test_lexer.o: src/asm/main_test_lexer.c.o

.PHONY : src/asm/main_test_lexer.o

# target to build an object file
src/asm/main_test_lexer.c.o:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/main_test_lexer.c.o
.PHONY : src/asm/main_test_lexer.c.o

src/asm/main_test_lexer.i: src/asm/main_test_lexer.c.i

.PHONY : src/asm/main_test_lexer.i

# target to preprocess a source file
src/asm/main_test_lexer.c.i:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/main_test_lexer.c.i
.PHONY : src/asm/main_test_lexer.c.i

src/asm/main_test_lexer.s: src/asm/main_test_lexer.c.s

.PHONY : src/asm/main_test_lexer.s

# target to generate assembly for a file
src/asm/main_test_lexer.c.s:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/main_test_lexer.c.s
.PHONY : src/asm/main_test_lexer.c.s

src/asm/op.o: src/asm/op.c.o

.PHONY : src/asm/op.o

# target to build an object file
src/asm/op.c.o:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/op.c.o
.PHONY : src/asm/op.c.o

src/asm/op.i: src/asm/op.c.i

.PHONY : src/asm/op.i

# target to preprocess a source file
src/asm/op.c.i:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/op.c.i
.PHONY : src/asm/op.c.i

src/asm/op.s: src/asm/op.c.s

.PHONY : src/asm/op.s

# target to generate assembly for a file
src/asm/op.c.s:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/op.c.s
.PHONY : src/asm/op.c.s

src/asm/read_args.o: src/asm/read_args.c.o

.PHONY : src/asm/read_args.o

# target to build an object file
src/asm/read_args.c.o:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/read_args.c.o
.PHONY : src/asm/read_args.c.o

src/asm/read_args.i: src/asm/read_args.c.i

.PHONY : src/asm/read_args.i

# target to preprocess a source file
src/asm/read_args.c.i:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/read_args.c.i
.PHONY : src/asm/read_args.c.i

src/asm/read_args.s: src/asm/read_args.c.s

.PHONY : src/asm/read_args.s

# target to generate assembly for a file
src/asm/read_args.c.s:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/read_args.c.s
.PHONY : src/asm/read_args.c.s

src/asm/semgraph_generator.o: src/asm/semgraph_generator.c.o

.PHONY : src/asm/semgraph_generator.o

# target to build an object file
src/asm/semgraph_generator.c.o:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/semgraph_generator.c.o
.PHONY : src/asm/semgraph_generator.c.o

src/asm/semgraph_generator.i: src/asm/semgraph_generator.c.i

.PHONY : src/asm/semgraph_generator.i

# target to preprocess a source file
src/asm/semgraph_generator.c.i:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/semgraph_generator.c.i
.PHONY : src/asm/semgraph_generator.c.i

src/asm/semgraph_generator.s: src/asm/semgraph_generator.c.s

.PHONY : src/asm/semgraph_generator.s

# target to generate assembly for a file
src/asm/semgraph_generator.c.s:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/semgraph_generator.c.s
.PHONY : src/asm/semgraph_generator.c.s

src/asm/writer.o: src/asm/writer.c.o

.PHONY : src/asm/writer.o

# target to build an object file
src/asm/writer.c.o:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/writer.c.o
.PHONY : src/asm/writer.c.o

src/asm/writer.i: src/asm/writer.c.i

.PHONY : src/asm/writer.i

# target to preprocess a source file
src/asm/writer.c.i:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/writer.c.i
.PHONY : src/asm/writer.c.i

src/asm/writer.s: src/asm/writer.c.s

.PHONY : src/asm/writer.s

# target to generate assembly for a file
src/asm/writer.c.s:
	$(MAKE) -f CMakeFiles/asm.dir/build.make CMakeFiles/asm.dir/src/asm/writer.c.s
.PHONY : src/asm/writer.c.s

src/vm/main.o: src/vm/main.c.o

.PHONY : src/vm/main.o

# target to build an object file
src/vm/main.c.o:
	$(MAKE) -f CMakeFiles/corewar.dir/build.make CMakeFiles/corewar.dir/src/vm/main.c.o
.PHONY : src/vm/main.c.o

src/vm/main.i: src/vm/main.c.i

.PHONY : src/vm/main.i

# target to preprocess a source file
src/vm/main.c.i:
	$(MAKE) -f CMakeFiles/corewar.dir/build.make CMakeFiles/corewar.dir/src/vm/main.c.i
.PHONY : src/vm/main.c.i

src/vm/main.s: src/vm/main.c.s

.PHONY : src/vm/main.s

# target to generate assembly for a file
src/vm/main.c.s:
	$(MAKE) -f CMakeFiles/corewar.dir/build.make CMakeFiles/corewar.dir/src/vm/main.c.s
.PHONY : src/vm/main.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... asm"
	@echo "... corewar"
	@echo "... src/asm/assembler.o"
	@echo "... src/asm/assembler.i"
	@echo "... src/asm/assembler.s"
	@echo "... src/asm/champ_generator.o"
	@echo "... src/asm/champ_generator.i"
	@echo "... src/asm/champ_generator.s"
	@echo "... src/asm/cmdgen_funcs.o"
	@echo "... src/asm/cmdgen_funcs.i"
	@echo "... src/asm/cmdgen_funcs.s"
	@echo "... src/asm/disassembler.o"
	@echo "... src/asm/disassembler.i"
	@echo "... src/asm/disassembler.s"
	@echo "... src/asm/lexer.o"
	@echo "... src/asm/lexer.i"
	@echo "... src/asm/lexer.s"
	@echo "... src/asm/main.o"
	@echo "... src/asm/main.i"
	@echo "... src/asm/main.s"
	@echo "... src/asm/main_test_lexer.o"
	@echo "... src/asm/main_test_lexer.i"
	@echo "... src/asm/main_test_lexer.s"
	@echo "... src/asm/op.o"
	@echo "... src/asm/op.i"
	@echo "... src/asm/op.s"
	@echo "... src/asm/read_args.o"
	@echo "... src/asm/read_args.i"
	@echo "... src/asm/read_args.s"
	@echo "... src/asm/semgraph_generator.o"
	@echo "... src/asm/semgraph_generator.i"
	@echo "... src/asm/semgraph_generator.s"
	@echo "... src/asm/writer.o"
	@echo "... src/asm/writer.i"
	@echo "... src/asm/writer.s"
	@echo "... src/vm/main.o"
	@echo "... src/vm/main.i"
	@echo "... src/vm/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

