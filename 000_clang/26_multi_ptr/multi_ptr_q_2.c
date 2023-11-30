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

    int*** ppp1 = &pp3;
    int*** ppp2 = &pp1;
    int*** ppp3 = &pp2;

    *ppp1 = *ppp3;      // pp3 = pp2
    **ppp2 = **ppp1;    // p2 = p3
    ***ppp3 -= ***ppp1; // num3 -= num3

    // num3 , num3, num3
    printf("%d, %d, %d", ***ppp1, ***ppp2, ***ppp3);
}