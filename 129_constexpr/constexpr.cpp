#include <iostream>
#include <vector>

using namespace std;

// 컴파일 중 할 수 있으면 컴파일 중 값으로 바꿔.
// 못하면 그냥 함수인거고.
constexpr int fibo(int n) {
    return n <= 2 ? 1 : (fibo(n - 1) + fibo(n - 2));
}

int main() {

    // 1 1 2 3 5
    cout << fibo(1) << endl;
    cout << fibo(2) << endl;
    cout << fibo(3) << endl;
    cout << fibo(4) << endl;
    cout << fibo(5) << endl;

    constexpr int compile_time_res = fibo(3);
    cout << compile_time_res; // 이건 됨. 컴파일 타임에 값을 알 수 있음.

    // 이건 런타임 도중 값을 알아야 하는 것이므로 compile error.
    int a;
    cin >> a;
    constexpr int k = fibo(a); // compile error.

    return 0;
}
