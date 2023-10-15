#include <stdio.h>
#include <stdlib.h>

/*
    malloc
    https://en.cppreference.com/w/c/memory/malloc
    void* malloc(size_t size);
    size 만큼의 byte를 반환함.
    void* 형을 반환하니 알아서 반환하는 것을 캐스팅해서 사용하라.
    메모리가 부족하면 NULL 반환

    free
    https://en.cppreference.com/w/c/memory/free
    void free(void* ptr);
*/

int main(void) {
    void* pa_num;
    int* p; // malloc으로 할당 받은 포인터로 연산 금지. 가급적이면 해당 주소를 복사해서 사용하라.

    pa_num = malloc(sizeof(int));
    p = pa_num; // void*는 캐스팅하지 않아도 됨.

    *p = 10;
    *p *= 3;

    printf("*p: %d\n", *p);

    free(pa_num);

    // 1. null ptr는 free로 전달해도 안전함. (또 free하는 실수 예방)
    // 2. 해제된 것이라는 것은 명확히 함.
    pa_num = NULL;
    p = NULL;
}