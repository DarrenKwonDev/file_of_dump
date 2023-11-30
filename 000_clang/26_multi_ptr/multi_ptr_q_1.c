#include <stdio.h>

int main(void) {
    int num1 = 10;
    int num2 = 13;
    int num3 = 19;

    int* p1 = &num2;
    int* p2 = &num1;
    int* p3 = &num3;

    int** pp1 = &p2;
    int** pp2 = &p3;
    int** pp3 = &p1;

    *pp1 = *pp2; // p2 = p3
    **pp2 *= 2;  // num3 *= 2
    pp3 = pp2;

    printf("%d, %d, %d", **pp1, **pp2, **pp3); // 38, 38, 38
}