#include <stdio.h>

int main(void) {
    int num1 = 15;
    int num2 = 30;
    int num3 = 45;

    int* ptr1 = &num1;
    int* ptr2 = &num2;
    int* ptr3 = &num3;

    ptr1 = ptr2; // ptr1이 num2를 가리키게 됨.
    ptr2 = ptr3; // ptr2가 num3를 가리키게 됨.

    // (ptr1, ptr2, ptr3) = (num2, num3, num3)

    *ptr3 *= 2;     // num3가 90 (num3 *= 2)
    *ptr1 += *ptr3; // num2가 120 (num2 += num3)
    *ptr2 *= 2;     // num3가 180 (num3 *= 2)

    printf("%d %d %d", num1, num2, num3);

    return 0;
}