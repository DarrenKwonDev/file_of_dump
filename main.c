#include <stdio.h>
#include <stdlib.h>

int main(void) {
    void* num;
    int* p; // malloc으로 할당 받은 포인터로 연산 금지. 가급적이면 해당 주소를 복사해서 사용하라.

    num = malloc(sizeof(int));
    p = num;

    *p = 10;
    *p *= 3;

    printf("*p: %d\n", *p);

    free(num);

    // 1. null ptr는 free로 전달해도 안전함.
    // 2. 해제된 것이라는 것은 명확히 함.
    num = NULL;
    p = NULL;
}