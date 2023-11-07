# 0.) Create Source and CMakeFile
# 1.) mkdir build
# 2.) cd build
# 3.) cmake ..   -  Generting the Build Files / Configure the Project (-Doption=value)
# 4.) cmake --build .
# 5.) ./Executable


cmake_minimum_required(VERSION 3.16)

project(helloworld VERSION 1.0.0 LANGUAGES C CXX)

# CMake configure

set(CMAKE_CXX_STANDARD 17) # C++ 표준으로 C++17을 사용
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # 지정된 C++ 표준(여기서는 C++17)을 지원하지 않는 컴파일러는 프로젝트를 빌드할 수 없습니다.
set(CMAKE_CXX_EXTENSIONS OFF) # 오직 ISO 표준 C++만을 사용하도록 강제합니다. 

# subdirectory에서 사용 가능
set(LIBRARY_NAME Library)
set(EXECUTABLE_NAME executable)

# cmake .. -DCOMPILE_EXECUTABLE=ON
option(COMPILE_EXECUTABLE "where to compile executable" OFF)

add_subdirectory(src)

if (COMPILE_EXECUTABLE)
    add_subdirectory(app)
else()
    message("w/o exe. compiling")
endif()