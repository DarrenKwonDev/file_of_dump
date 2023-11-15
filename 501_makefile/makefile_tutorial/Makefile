# ############
# variable
# ############
# variable only can be STRING
# "", '' has no meaning
DEBUG_MODE = 1 # not int, it's string
EXECUTABLE_NAME = main

# ############
# implicit rules
# ############
# https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html
# `make -p` to see all predefined variables

# examples
# CC = Program for compiling C programs; default ‘cc’.
# CXX = Program for compiling C++ programs; default ‘g++’.
# CFLAGS = Extra flags to give to the C compiler.
# CXXFLAGS = Extra flags to give to the C++ compiler.
# CPPFLAGS = Extra flags to give to the C preprocessor and programs that use it (the C and Fortran compilers).
# LDFLAGS = Extra flags to give to compilers when they are supposed to invoke the linker, ‘ld’, such as -L. Libraries (-lfoo) should be added to the LDLIBS variable instead.

# you cans chanege these variables by cli
# e.g.) make build CXX_STANDARD=c++14
CC = clang
CXX = clang++

C_STANDARD = c11
CXX_STANDARD = c++17

CXX_WARNINGS = -Wall -Wextra -Wpedantic -Werror
CFLAGS = -std=$(C_STANDARD) $(CXX_WARNINGS)
CXXFLAGS = -std=$(CXX_STANDARD) $(CXX_WARNINGS)
LDFLAGS =

COMPILER_CALL = $(CXX) $(CXXFLAGS) 

ifeq ($(DEBUG_MODE), 1)
# optimzation level 0
	CXXFLAGS += -g -O0 
else
# optimization level 3 (highest)
	CXXFLAGS += -O3 
endif

# ############
# TARGETS
# ############
# target: prerequisites
# 	commands
# ############

# if no arg provied, make will execute the first target
build: mylib.o main.o 
	$(COMPILER_CALL) main.o mylib.o $(LDFLAGS) -o $(EXECUTABLE_NAME) 

# project가 커지면 모두 컴파일하는 것이 느려지곤 함.
main.o:
	$(COMPILER_CALL) -c ./main.cpp

mylib.o:
	$(COMPILER_CALL) -c ./mylib.cpp

execute:
	./main

clean:
	rm -f *.o
	rm -f main