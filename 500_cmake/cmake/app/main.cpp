#include <iostream>

#include "config.hpp"
#include "my_lib.h"

int main() {
    std::cout << project_name << std::endl;
    std::cout << project_version << std::endl;

    print_hello_world();

    return 0;
}
