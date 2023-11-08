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

# fetch content
# https://cmake.org/cmake/help/v3.27/module/FetchContent.html
include(FetchContent)
FetchContent_Declare(
    FMT # https://github.com/fmtlib/fmt/blob/master/CMakeLists.txt#L137C9-L137C12
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git # 여기 적은 곳을 clone함.
    GIT_TAG 10.1.1 # https://github.com/fmtlib/fmt/releases/tag/10.1.1
    GIT_SHALLOW TRUE # git clone operation will be given the --depth 1 option
)
FetchContent_Declare(
    spdlog # https://github.com/gabime/spdlog/blob/v1.x/CMakeLists.txt#L13C9-L13C15
    GIT_REPOSITORY https://github.com/gabime/spdlog
    GIT_TAG v1.12.0 
    GIT_SHALLOW TRUE 
)
FetchContent_Declare(
    cxxopts # https://github.com/jarro2783/cxxopts/blob/master/CMakeLists.txt#L30
    GIT_REPOSITORY https://github.com/jarro2783/cxxopts
    GIT_TAG v3.1.1 
    GIT_SHALLOW TRUE 
)
FetchContent_Declare(
    Catch2 # https://github.com/catchorg/Catch2/blob/devel/CMakeLists.txt#L34C9-L34C15
    GIT_REPOSITORY https://github.com/catchorg/Catch2
    GIT_TAG v3.4.0
    GIT_SHALLOW TRUE 
)
FetchContent_MakeAvailable(FMT spdlog cxxopts Catch2)



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

