#include <stdio.h>

const int g_num = 235; // 상수

// 함수 내부에서 w, h를 내부에서 변경할 수 없다는 것을 의미함.
int calc(const int w, const int h) {
    const int area = w * h;
    // w = 3; // error: cannot assign to variable 'a' with const-qualified type 'const int'
    return area;
}

int main(void) {
    int k;
    k = calc(10, 8);
    printf("%d\n", k);

    // g_num = 1000; // error: cannot assign to variable 'g_num' with const-qualified type 'const int'

    printf("%d\n", g_num);
    return 0;
}