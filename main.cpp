#include <iostream>

int main(void) {

    double a = 0.1 + 0.1 + 0.1;
    double b = 0.3;

    if (a == b) {
        std::cout << "same 1" << std::endl;
    }
    if (abs(a - b) <= 1e-9) {
        std::cout << "same 2" << std::endl;
    }

    return 0;
}