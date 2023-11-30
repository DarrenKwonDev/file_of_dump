#include <iostream>

using namespace std;

void swap(int& a, int& b) {
    int tmp = b;
    b = a;
    a = tmp;
}

int main(void) {
    int k = 3;
    int k2 = 10;
    int* p = &k;
    int& r = k;

    r = k2;     // k = k2와 같음.
    cout << k;  // ref가 바뀌었으니 원본도 mutate
    cout << *p; // 포인터 역참조.

    int a = 2;
    int b = 1;
    swap(a, b); // 호출자 타입이 아닌 일반 값을 담은 변수를 넣어서 호출 가능.
    cout << a << b;

    return 0;
}