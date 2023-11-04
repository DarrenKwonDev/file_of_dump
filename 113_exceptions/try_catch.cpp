#include <exception>
#include <iostream>

int main(void) {

    std::string str = "test shit";

    try {
        // error
        // terminating with uncaught exception
        char ch = str.at(256);

    } catch (const std::out_of_range& e) {
        // handle out of range exception
        std::cerr << e.what() << "\n";
    } catch (const std::exception& e) {
        // handle other exception.
        std::cerr << e.what() << "\n";
    }

    return 0;
}
