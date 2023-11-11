#include <iostream>
#include <vector>

using namespace std;

template <int T>
struct Fibo {
    enum {
        value = (Fibo<T - 1>::value + Fibo<T - 2>::value)
    };
};

template <>
struct Fibo<0> {
    enum { value = 1 };
};

template <>
struct Fibo<1> {
    enum { value = 1 };
};

template <>
struct Fibo<2> {
    enum { value = 1 };
};

int main() {
    int x = Fibo<5>::value;
    cout << x << endl;

    return 0;
}
