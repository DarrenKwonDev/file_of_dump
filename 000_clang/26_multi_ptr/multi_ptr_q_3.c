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

    pp1 = pp3;
    **pp2 += **pp3; // num3 += num2
    pp3 = pp2;

    *ppp1 = *ppp2; // pp3 = pp1
    ppp2 = ppp3;
    *ppp3 = *ppp2; // pp2 = pp2
}