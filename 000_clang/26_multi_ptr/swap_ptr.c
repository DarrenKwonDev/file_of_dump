#include <stdio.h>
#include <string.h>

void swap_ptr(int** p, int** q) {
    int* temp = *p;
    *p = *q;
    *q = temp;
}

int main(void) {
    int a = 10;
    int b = 20;

    int* p = &a;
    int* q = &b;

    printf("%p %p\n", p, q);
    printf("%d %d\n", *p, *q);

    // p의 주소와 q의 주소를 바꾸고 싶습니다.
    swap_ptr(&p, &q);

    printf("%p %p\n", p, q);
    printf("%d %d\n", *p, *q);
}