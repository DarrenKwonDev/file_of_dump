# 0.) Create Source and CMakeFile
# 1.) mkdir build
# 2.) cd build
# 3.) cmake ..   -  Generting the Build Files / Configure the Project
# 4.) cmake --build .
# 5.) ./Executable


cmake_minimum_required(VERSION 3.16)

project(helloworld VERSION 1.0.0 LANGUAGES C CXX)

# [STATIC | SHARED | MODULE]
add_library(lib STATIC my_lib.cpp)

add_executable(outcom main.cpp)

# PUBLIC | PRIVATE | INTERFACE
target_link_libraries(outcom PUBLIC lib)
