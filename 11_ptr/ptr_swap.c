#include <stdio.h>

void swap_int(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main(void) {
    int num1 = 10;
    int num2 = 20;

    swap_int(&num1, &num2);

    printf("%d %d", num1, num2);
    return 0;
}