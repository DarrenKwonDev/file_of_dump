cmake_minimum_required(VERSION 3.13)

project(googletest_sample)

include(FetchContent)

FetchContent_Declare(
  googletest
	GIT_REPOSITORY https://github.com/google/googletest
	GIT_TAG release-1.11.0
)

# fetch해온 라이브러리의 속성 조회. (fetch가 성공적인지 체크하는 역할도 함.)
FetchContent_GetProperties(googletest)
# if fetch success, then below variables are set.
#googletest_POPULATED
#googletest_SOURCE_DIR
#googletest_BUILD_DIR
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

# 정적 라이브러리 생성
add_library(sumLibrary STATIC LibraryCode.cpp)

# mainApp 생성 후 lib 링킹
add_executable(mainApp main.cpp)
target_link_libraries(mainApp sumLibrary)

# testRunner 생성 후 lib 링킹
add_executable(testRunner testRunner.cpp)
target_link_libraries(testRunner sumLibrary gtest_main gmock_main)