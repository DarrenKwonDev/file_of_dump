CC = clang
CXX = clang++

thing_wrong := *.o # Don't do this! '*' will not get expanded
thing_right := $(wildcard *.o)

hello:
# target name
	echo $@
# prerequisites
	echo $^

	@echo "This make line will not be printed"

print: $(wildcard *.c)
	ls -la  $?
