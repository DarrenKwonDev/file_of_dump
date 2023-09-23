#include <stdio.h>

/*
    값을 보호하는 ptr
*/

void do_something(const int* p) {
    // 이 함수 내에서 p를 통해서 원본의 값을 변경하는 것이 불가능.
    // 값을 안전하게 보호할 수 있다.
}

int main(void) {
    int a = 3;
    int b = 9;

    // 값을 보호하는 ptr 둘이 같은 의미
    const int* p = &a;
    int const* q = &a;
    // *p = 5; // error

    // 주소를 보호하는 ptr
    int* const r = &a; // const pointer
    // r = &b;            // error

    // 값을 보호하는 ptr는 ptr 통한 값 변경을 막는 것이지, 값 자체는 바꿀 수 있다.
    printf("%d, %p\n", *p, p);
    a = 10; // ok
    printf("%d, %p\n", *p, p);

    printf("%d, %p\n", *q, q);
    a = 8; // ok
    printf("%d, %p\n", *q, q);

    return 0;
}
