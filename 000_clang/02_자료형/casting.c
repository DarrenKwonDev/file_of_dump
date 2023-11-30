#include <float.h>
#include <stdio.h>

int main(void) {
    int num1 = 3.14; // 3으로 형변환 됨.
    printf("%d\n", num1);

    double num2 = 3; // 3.0으로 형변환 됨.
    printf("%f\n", num2);

    // 정수 끼리의 나눗셈은 정수임. 실수가 연산, 피연산 두 곳 중 하나라도 들어가면 실수가 됨.
    int num3 = 10 / 3;    // 나누어 떨어 지지 않아도 정수가 반환됨. 나머지는 버림.
    printf("%d\n", num3); // 3

    double num4 = 10 / 3.0; // 실수가 하나라도 들어가야 실수로 반환됨.
    printf("%f\n", num4);   // 3.3333
}