#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cout << "===간단한 암시적 casting===" << endl;

    int num1 = 3.4;
    cout << num1 << endl; // 3으로 내림.

    long long int num2 = num1; // int를 long으로 캐스팅(더 큰 범위이므로) 허용
    cout << num2 << endl;

    int q = 3 / 2.0;
    float f_q = 3 / 2.0;

    cout << q << endl;   // 1. 정수 반환
    cout << f_q << endl; // 1.5 float 반환.

    return 0;
}