#include <iostream>
#include <list>

using namespace std;

template <typename T>
T Add(T a, T b) {
    return a + b;
}

int main() {
    cout << Add<double>(1.1, 2.5) << endl;

    return 0;
}