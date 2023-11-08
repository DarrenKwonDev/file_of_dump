# 0.) Create Source and CMakeFile
# 1.) mkdir build
# 2.) cd build
# 3.) cmake ..   -  Generting the Build Files / Configure the Project (-Doption=value)
# 4.) cmake --build .
# 5.) ./Executable


cmake_minimum_required(VERSION 3.16)

# https://cmake.org/cmake/help/v3.27/command/project.html#project
# ${PROJECT_NAME} wil be setted
project(helloworld VERSION 1.0.0 LANGUAGES C CXX)

# CMake configure
# cmake-variables를 참고해보자.
# https://cmake.org/cmake/help/v3.27/manual/cmake-variables.7.html
set(CMAKE_CXX_STANDARD 17) # C++ 표준으로 C++17을 사용
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # 지정된 C++ 표준(여기서는 C++17)을 지원하지 않는 컴파일러는 프로젝트를 빌드할 수 없습니다.
set(CMAKE_CXX_EXTENSIONS OFF) # 오직 ISO 표준 C++만을 사용하도록 강제합니다. 


# 변수 정의 시 subdirectory에서 사용 가능
set(LIBRARY_NAME Library)
set(EXECUTABLE_NAME executable)

# cmake function
# https://cmake.org/cmake/help/latest/command/function.html
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(AddGitSubmodule)

# call custom cmake function
add_git_submodule(external/json)

# cmake .. -DCOMPILE_EXECUTABLE=ON
option(COMPILE_EXECUTABLE "where to compile executable" ON)


add_subdirectory(src)
add_subdirectory(configured)
add_subdirectory(external)

if (COMPILE_EXECUTABLE)
    add_subdirectory(app)
else()
    message("w/o exe. compiling")
endif()

