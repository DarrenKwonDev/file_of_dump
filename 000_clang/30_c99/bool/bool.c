#include <stdbool.h>
#include <stdio.h>

/*
    C99 지원되는 환경이면 stdbool.h를 사용하는 편이 깔끔함.
*/
int main() {
    _Bool a = 9;
    bool b = 19; // bool 형은 stdbool.h가 include 되어야만 사용 가능

    // 0 외의 다른 값은 1로 변환됨.
    printf("%d", a); // 1
    printf("%d", b); // 1

    printf("%d", true);  // 1. #define true (1) 재정의 불필요
    printf("%d", false); // 0. #define false (0) 재정의 불필요

    return 0;
}
