#include <stdio.h>

/*
    반환형 (*변수명)(매개변수 목록)
*/

int add(int a, int b) {
    return a + b;
}

void print(int a) {
    printf("%d\n", a);
}

int calc(int (*fp)(int, int), int a, int b) {
    return fp(a, b);
}

int main(void) {
    // 1. fp는 포인터를 반환한다.(포인터이다)
    // 2. 그 포인터는 (int, int) -> int 인 함수 포인터다.
    int (*fp)(int, int) = &add;

    // 1. fp2는 포인터를 반환한다.(포인터이다)
    // 2. 그 포인터는 (int) -> void인 함수 포인터다.
    void (*fp2)(int) = &print;

    // 1. fun은 [2]인 배열이며 포인터를 반환한다.(포인터이다)
    // 2. 그 포인터는 (float, float) -> int인 함수 포인터이다.
    int (*fun[2])(float, float); // 함수 포인터 원소 2개 배열

    // 1. func는 int, void (*)(int) 를 인자로 받으며 포인터(*)를 반환한다.
    // 2. 그리고 그 포인터는 (int)를 받고 void를 받환하는 함수이다.
    void (*func(int, void (*)(int)))(int);

    printf("%d\n", calc(fp, 10, 20)); // 30

    char (*fo)(void*);
    int* (*foo)(int, void (*)(int));
    unsigned int** (*foo2)(char (*)(void*));

    return 0;
}
