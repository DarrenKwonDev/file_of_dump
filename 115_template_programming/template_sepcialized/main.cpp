#include <iostream>

using namespace std;

template <typename V>
void Print(const V value) {
    std::cout << "1. Print a value: " << value << std::endl;
}

// bool이 들어올 경우.
template <>
void Print(bool b) {
    std::cout << "2. Print a value: " << std::boolalpha << b << std::endl;
}

int main() {
    Print(true);
    Print(14);
    Print(3.14f);
    Print("I love C++!");

    return 0;
}
