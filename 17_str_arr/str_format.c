#include <stdio.h>

/*
    %[flags][width][.precision][length]specifier
    순서가 중요.

    출처 : https://en.cppreference.com/w/c/io/fprintf
    <specifier(서식 지정자)>
    -   %d: 부호 있는 10진수 정수
    -   %u: 부호 없는 10진수 정수
    -   %o: 부호 없는 8진수 정수
    -   %x: 부호 없는 16진수 정수 + 앞에 0x 붙음
    -   %X: 부호 없는 16진수 정수(대문자) + 앞에 0X 안붙음
    -   %f: 부호 있는 10진수 실수
    -   %e: 부호 있는 10진수 실수(지수 표현)
    -   %E: 부호 있는 10진수 실수(지수 표현, 대문자)
    -   %p: 포인터의 주소 값. (void*)만 받음
*/

int main(void) {
    printf("%5d\n", 10);   // "   10"
    printf("%05d\n", 10);  // "00010"
    printf("%-5d\n", 10);  // "10   " 왼쪽 정렬
    printf("%+5d\n", -10); // "  -10" 부호 출력
    printf("%-+5d\n", 10); // "+10  " 왼쪽 정렬하되 부호 출력

    printf("%5.1f\n", 3.141592); // "  3.1". 5 width에  소수점 1 자리 까지.

    return 0;
}