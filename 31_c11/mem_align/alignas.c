#include <stdalign.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a;
    alignas(4096) int b; // 4096 바이트로 정렬됨. 즉, b의 포인터 주소는 4096의 배수임.

    printf("%p %p\n", &a, &b);

    printf("%lu\n", (size_t)&a % 4096); // 4096으로 나누어떨어지지 않음.
    printf("%lu\n", (size_t)&b % 4096); // 4096으로 정렬되었으므로 0으로 나누어 떨어질 것.

    return 0;
}