#include <stdio.h>

int main(void) {
    int a = 0;
    int b = 3;
    int c = 1;

    /*
        1. --a가 먼저 평가됨 (-1 && c++ || --b)
        2. && 연산이므로 c++ || --b가 평가 대상이 됨
        3. 1 || --b 이므로 short circuit에 의해 true로 판정되고 --b는 연산되지 않음
        4. if 조건문을 벗어나면서 c++ 후위 연산이 연산됨
        5. 결과적으로 a = -1, b = 3, c = 2가 됨.

     */
    if (--a && c++ || --b) {
        printf("It's true!\n");
    }
    printf("%d, %d, %d\n", a, b, c);
}