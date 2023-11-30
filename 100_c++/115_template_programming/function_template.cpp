#include <iostream>
#include <list>

using namespace std;

// template <class T>
// typename과 class의 차이가 사실상 없음. 마음에 드는 것을 쓰시라.
template <typename T>
T Add(T a, T b) {
    return a + b;
}

int main() {
    // 일반적인 template function
    cout << Add<double>(1.1, 2.5) << endl;

    // <>를 적지 않았음에도 작동함.
    cout << Add(3, 5) << endl;

    return 0;
}