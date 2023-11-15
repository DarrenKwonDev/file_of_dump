# ############
# variable
# ############
# variable only can be STRING
# "", '' has no meaning
DEBUG_MODE = 1 # not int, it's string

INCLUDE_DIR = include
SOURCE_DIR = src
BUILD_DIR = build

# ############
# implicit rules
# ############
# https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html
# `make -p` to see all predefined variables

# examples
# CC = Program for compiling C programs; default ‘cc’.
# CXX = Program for compiling C++ programs; default ‘g++’.
# CFLAGS = Extra flags to give to the C compiler.
# CXXFLAGS = compiler flags. 주로 컴파일 시 경고 옵션, 최적화 옵션, C++ 표준 버전 등 추가.
# CPPFLAGS = preprocessor flags. 주로 헤더 파일의 경로를 지정하거나 매크로 정의를 추가.
# LDFLAGS = linker flags. 주로 라이브러리 경로 및 라이브러리를 지정하는 데 사용

# you cans chanege these variables by cli
# e.g.) make build CXX_STANDARD=c++14
CC = clang
CXX = clang++

C_STANDARD = c11
CXX_STANDARD = c++17


CFLAGS = -std=$(C_STANDARD) $(CXX_WARNINGS)
CXX_WARNINGS = -Wall -Wextra -Wpedantic -Werror

CXXFLAGS = -std=$(CXX_STANDARD) $(CXX_WARNINGS)
CPPFLAGS = -I $(INCLUDE_DIR)
LDFLAGS =


# optimzation level 0
# optimization level 3 (highest)
# you can mutate value likes `make build DEBUG_MODE=0`
ifeq ($(DEBUG_MODE), 1)
CXXFLAGS += -g -O0 
EXECUTABLE_NAME = main_debug
else
CXXFLAGS += -O3 
EXECUTABLE_NAME = main_release
endif

# pattern matching and pattern substitution
CXX_SOURCES = $(wildcard $(SOURCE_DIR)/*.cpp)
CXX_OBJECTS = $(patsubst $(SOURCE_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(CXX_SOURCES))

# compiler call build
CXX_COMPILER_CALL = $(CXX) $(CXXFLAGS) $(CPPFLAGS)

# ############
# TARGETS
# ############
# target: prerequisites
# 	commands
# ############

# if no arg provied, make will execute the first target
# as convension, first target should be all.
all: create build

create:
# @ snmbol -> don't show termnial output
	@mkdir -p $(BUILD_DIR)

build: create $(CXX_OBJECTS)
	$(CXX_COMPILER_CALL) $(CXX_OBJECTS) $(LDFLAGS) -o $(BUILD_DIR)/$(EXECUTABLE_NAME)

execute:
	./${BUILD_DIR}/$(EXECUTABLE_NAME)



# ############
# patterns
# ############
# https://www.gnu.org/software/make/manual/html_node/Pattern-Rules.html
# 이 규칙을 사용하면 Makefile에서 개별적으로 
# 각 .cpp 파일에 대한 컴파일 규칙을 작성할 필요 없이 자동으로 컴파일을 수행할 수 있습니다.
# %@ : the file name of the target
# $< : the name of the first prerequisite
# $^ : the names of all the prerequisites

# 모든 .o 파일은 .cpp 파일로부터 생성된다.
# $(CXX_COMPILER_CALL) -c $< -o $@ 명령어를 통해서.
# $< : .cpp 파일의 이름을 의미.
# $@ : .o 파일의 이름을 의미.
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(CXX_COMPILER_CALL) -c $< -o $@


# ############
# phony
# ############
# 특정 명령어가 파일 이름이 아닌 명령어임을 지정함.
# 아래는 각각의 명령어가 파일 이름이 아님을 지정하는 것.
.PHONY: create build execute clean

.PHONY: clean # phony target. 일괄 지정할수도 있고, 이렇게 단 건만 지정할 수도.
clean:
	rm -f $(BUILD_DIR)/*.o
	rm -f $(BUILD_DIR)/$(EXECUTABLE_NAME)