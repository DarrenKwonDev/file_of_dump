#include <stdio.h>

void compare(const int* a, const int* b) {
    printf("%d\n", a == b);   // 주소값 비교. 주소는 다르니까 0.
    printf("%d\n", *a == *b); // 값 비교. 주소는 다르지만 값은 같으니 1.
}

int main(void) {
    int num1 = 10;
    int num2 = 10;

    compare(&num1, &num2);
    return 0;
}