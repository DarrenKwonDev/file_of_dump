#include <bits/stdc++.h>
using namespace std;

int static_inc(int num) {
    // 1. 재호출 하더라도 한 번 초기화 되었으므로 0으로 재할당되지 않음.
    // 2. 선언된 함수 스코프 내부에서만 접근 가능함.
    static int k = 0;
    k += num;
    return k;
}

int main(void) {

    cout << static_inc(10) << endl;

    cout << static_inc(20) << endl; // 30.

    return 0;
}
