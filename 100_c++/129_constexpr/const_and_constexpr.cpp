#include <iostream>

using namespace std;

int main() {

    const int a = 3;
    a = 10; // compile error
    // cannot assign to variable 'a' with const-qualified type 'const int'

    constexpr int b = 3;
    b = 10; // compile error
    // cannot assign to variable 'b' with const-qualified type 'const int'

    int c = 3;
    constexpr int d = c; // compile error
    // constexpr variable 'd' must be initialized by a constant expression

    const int e = 3;
    constexpr int f = e; // good.

    constexpr int g = 3;
    constexpr int h = g; // good.

    return 0;
}
