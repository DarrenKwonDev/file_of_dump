set(LIBRARY_SOURCES my_lib.cpp)
set(LIBRARY_HEADERS my_lib.h)
set(LIBRARY_INCLUDES 
"./"
"${CMAKE_BINARY_DIR}/configured_files/include"
)


# static lib 생성
add_library(${LIBRARY_NAME} STATIC
    ${LIBRARY_SOURCES}
    ${LIBRARY_HEADERS}
)

# static lib 의 include 경로 설정
target_include_directories(${LIBRARY_NAME} PUBLIC 
    ${LIBRARY_INCLUDES}
)

# LIBRARY_NAME에 fmt, spdlog, cxxopts 라이브러리 링크
target_link_libraries(${LIBRARY_NAME} PUBLIC 
    fmt::fmt
    spdlog::spdlog
    cxxopts::cxxopts
)