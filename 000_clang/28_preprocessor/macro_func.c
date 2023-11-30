#include <stdio.h>

#define ADD(x, y) x + y
#define ADD2(x, y) (x + y) // 매크로 함수 구현은 괄호로 묶을 것 권고.

int main() {
    int a, b;
    a = 10;
    b = 20;

    int res = 10 * ADD(a, b);
    printf("%d\n", res); // 300을 예상했으나.. 120임.
    // 10 * a + b = 120

    res = 10 * ADD2(a, b);
    printf("%d\n", res); // 300
    // 매크로 함수의 괄호 덕분에 10 * (a + b) = 300이 됨.

    return 0;
}
