DEBUG_MODE = 1

ifeq ($(DEBUG_MODE),1)
    # DEBUG_MODE가 1로 설정된 경우
    CXXFLAGS += -g -O0 
    EXECUTABLE_NAME = main_debug
else
    # DEBUG_MODE가 1로 설정되지 않은 경우
    CXXFLAGS += -O3 
    EXECUTABLE_NAME = main_release
endif

all: 
	echo "Executable name is $(EXECUTABLE_NAME)"
