#include <stdio.h>

/*
    주소를 보호하는 ptr
    1. 포인터 값(주소)를 변경할 수 없다.
    2.
*/
int main(void) {
    int a = 3;
    int b = 5;

    int* const p = &a; // const pointer

    // 둘 다 pointer의 주소를 변경하려는 것이므로 에러.
    p = &b; // error
    p++;    // error

    // printf("%d, %d\n", a, *p);
    // printf("%p, %p\n", &a, p);

    return 0;
}
