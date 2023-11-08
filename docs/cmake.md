<!-- toc -->

-   [docs](#docs)
-   [installation](#installation)
-   [keywords](#keywords)
-   [tips](#tips)
-   [Generating a Project](#generating-a-project)
-   [Generator for GCC and Clang](#generator-for-gcc-and-clang)
-   [Generator for MSVC](#generator-for-msvc)
-   [Specify the Build Type](#specify-the-build-type)
-   [Passing Options](#passing-options)
-   [Specify the Build Target (Option 1)](#specify-the-build-target-option-1)
-   [Specify the Build Target (Option 2)](#specify-the-build-target-option-2)
-   [Run the Executable](#run-the-executable)
-   [Different Linking Types](#different-linking-types)
    -   [PUBLIC](#public)
    -   [PRIVATE](#private)
    -   [INTERFACE](#interface)
-   [Different Library Types](#different-library-types)
    -   [Library](#library)
    -   [Shared (동적 라이브러리)](#shared-%EB%8F%99%EC%A0%81-%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC)
    -   [Static (정적 라이브러리)](#static-%EC%A0%95%EC%A0%81-%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC)

<!-- tocstop -->

## docs

C/Cpp 버전은 하위를 쓰더라도 build process는 최신 방식을 쓰자.  
3.0 이상의 modern CMake를 권고함.

https://cmake.org/cmake/help/v3.27/index.html

[official site](https://cmake.org/)  
[An Introduction to Modern CMake](https://cliutils.gitlab.io/modern-cmake/)  
[effective_modern_cmake](https://gist.github.com/mbinna/c61dbb39bca0e4fb7d1f73b0d66a4fd1)

## installation

```bash
sudo apt-get update
sudo apt-get upgrade

# Mandatory
sudo apt-get install gcc g++ gdb
sudo apt-get install make cmake
sudo apt-get install git
sudo apt-get install doxygen
sudo apt-get install python3 python3-pip

# Optional
sudo apt-get install lcov gcovr
sudo apt-get install ccache
sudo apt-get install cppcheck
sudo apt-get install llvm clang-format clang-tidy
sudo apt-get install curl zip unzip tar
sudo apt-get install graphviz
```

```bash
brew install git
brew install make # for Makefile
brew install cmake # for Cmake
brew install doxygen
brew install lcov
brew install gcovr
brew install ccache
```

## keywords

```bash
cmake_minimum_required
project
add_subdirectory

add_library
add_executable

target_link_libraries # executable에 library를 링크
target_include_directories # Add include directories to a target.
```

-   cmake variables

https://cmake.org/cmake/help/v3.27/manual/cmake-variables.7.html

-   configure files

https://cmake.org/cmake/help/latest/command/configure_file.html

## tips

-   소스 코드가 든 폴더마다 CMakeLists.txt를 만들어야 함.

---

## Generating a Project

```bash
cmake [<options>] -S <path-to-source> -B <path-to-build>
```

Assuming that a CMakeLists.txt is in the root directory, you can generate a project like the following.

```bash
mkdir build
cd build
cmake -S .. -B . # Option 1
cmake .. # Option 2
```

Assuming that you have already built the CMake project, you can update the generated project.

```bash
cd build
cmake .
```

## Generator for GCC and Clang (-G)

```bash
cd build
cmake -S .. -B . -G "Unix Makefiles" # Option 1
cmake .. -G "Unix Makefiles" # Option 2
```

## Generator for MSVC (-G)

```bash
cd build
cmake -S .. -B . -G "Visual Studio 16 2019" # Option 1
cmake .. -G "Visual Studio 16 2019" # Option 2
```

## Specify the Build Type (debug or release)

Per default, the standard type is in most cases the debug type.
If you want to generate the project, for example, in release mode you have to set the build type.

```bash
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
```

## Passing Options (-D)

If you have set some options in the CMakeLists, you can pass values in the command line.

```bash
cd build
cmake -DMY_OPTION=[ON|OFF] ..
```

## Specify the Build Target (Option 1)

The standard build command would build all created targets within the CMakeLists.
If you want to build a specific target, you can do so.

```bash
cd build
cmake --build . --target ExternalLibraries_Executable
```

The target _ExternalLibraries_Executable_ is just an example of a possible target name.
Note: All dependent targets will be built beforehand.

## Specify the Build Target (Option 2)

Besides setting the target within the cmake build command, you could also run the previously generated Makefile (from the generating step).
If you want to build the _ExternalLibraries_Executable_, you could do the following.

```bash
cd build
make ExternalLibraries_Executable
```

## Run the Executable

After generating the project and building a specific target you might want to run the executable.
In the default case, the executable is stored in _build/5_ExternalLibraries/app/ExternalLibraries_Executable_, assuming that you are building the project _5_ExternalLibraries_ and the main file of the executable is in the _app_ dir.

```bash
cd build
./bin/ExternalLibraries_Executable
```

## Different Linking Types

```cmake
add_library(A ...)
add_library(B ...)
add_library(C ...)
```

### PUBLIC

```cmake
target_link_libraries(A PUBLIC B)
target_link_libraries(C PUBLIC A)
```

When A links in B as _PUBLIC_, it says that A uses B in its implementation, and B is also used in A's public API. Hence, C can use B since it is part of the public API of A.

### PRIVATE

```cmake
target_link_libraries(A PRIVATE B)
target_link_libraries(C PRIVATE A)
```

When A links in B as _PRIVATE_, it is saying that A uses B in its
implementation, but B is not used in any part of A's public API. Any code
that makes calls into A would not need to refer directly to anything from
B.

### INTERFACE

```cmake
add_library(D INTERFACE)
target_include_directories(D INTERFACE {CMAKE_CURRENT_SOURCE_DIR}/include)
```

In general, used for header-only libraries.

## Different Library Types

### Library

A binary file that contains information about code.
A library cannot be executed on its own.
An application utilizes a library.

### Shared (동적 라이브러리)

-   Linux: \*.so
-   MacOS: \*.dylib
-   Windows: \*.dll

Shared libraries reduce the amount of code that is duplicated in each program that makes use of the library, keeping the binaries small.
Shared libraries will however have a small additional cost for the execution.
In general the shared library is in the same directory as the executable.

### Static (정적 라이브러리)

-   Linux/MacOS: \*.a
-   Windows: \*.lib

Static libraries increase the overall size of the binary, but it means that you don't need to carry along a copy of the library that is being used.
As the code is connected at compile time there are not any additional run-time loading costs.
