# https://cmake.org/cmake/help/latest/command/configure_file.html
configure_file(
    "./config.hpp.in" 
    "${CMAKE_BINARY_DIR}/configured_files/include/config.hpp" ESCAPE_QUOTES
)