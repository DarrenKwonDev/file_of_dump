#include <iostream>

#include "my_lib.h"
#include "spdlog/spdlog.h"

void print_hello_world() {
    std::cout << "Hello World!\n";

    spdlog::info("Welcome to spdlog!");
}
