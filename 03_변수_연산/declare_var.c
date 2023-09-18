#include <stdio.h>

int main(void)
{
    /*
        C89 표준에서는 변수 선언을 body 상단부에서만 가능하다.
    */
    int a = 10;
    int b = 20;

    printf("%d, %d\n", a, b);

    int c = 30; // error: ISO C90 forbids mixing declarations and code

    return 0;
}