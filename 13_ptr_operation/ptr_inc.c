#include <stdio.h>

int main() {
    int a = 3;
    int* p = &a;

    printf("%p\n", p); // 0x7ffeeb0b9a9c
    p++;               // 주소값이 4바이트 증가한다.
    printf("%p\n", p); // 0x7ffeeb0b9a9c
    return 0;
}