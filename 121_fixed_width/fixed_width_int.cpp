#include <iostream>

using namespace std;

int main(void) {
    char16_t ch1 = 'a';
    char32_t ch2 = '2';
    cout << sizeof(ch1) << endl; // 2
    cout << sizeof(ch2) << endl; // 4

    int16_t k = 3;
    int32_t a = 32;
    int64_t b = 101;
    cout << sizeof(k) << endl; // 2
    cout << sizeof(a) << endl; // 4
    cout << sizeof(b) << endl; // 8

    uint16_t x;
    uint32_t y;
    uint64_t z;
    cout << sizeof(x) << endl; // 2
    cout << sizeof(y) << endl; // 4
    cout << sizeof(z) << endl; // 8

    // etc ...

    return 0;
}
