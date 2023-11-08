#include <iostream>

#include "config.hpp"
#include "my_lib.h"
#include "nlohmann/json.hpp"

int main() {
    std::cout << project_name << std::endl;
    std::cout << project_version << std::endl;

    std::cout << "external lib version check " << NLOHMANN_JSON_VERSION_MAJOR << std::endl;

    print_hello_world();

    return 0;
}