#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    calloc
    https://en.cppreference.com/w/c/memory/calloc
    void* calloc( size_t num, size_t size );
    1. 자료형의 size와 갯수 num을 따로 지정하여 힙 메모리 할당
    2. 모든 바이트를 0으로 초기화해 줌.

    보면 malloc 상위 호환인 것 같은데 잘 안 쓴다.
    왜?
    malloc + memset으로 대체 가능하고, 0외의 다른 값으로 초기화가능하기 때문임.
*/

int main(void) {
    int* pa_a = calloc(sizeof(int), 3);

    // 위는 아래와 동일하다.
    void* pa_b = malloc(sizeof(int) * 3);
    memset(pa_b, 0, sizeof(int) * 3);

    free(pa_a);
    pa_a = NULL;

    free(pa_b);
    b = NULL;
}