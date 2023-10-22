#include <stdio.h>

int factorial(int n) {
    if (n == 1) {
        return n;
    }
    return n * factorial(n - 1);
}

int main(void) {
    printf("%d\n", factorial(1));
    printf("%d\n", factorial(2));
    printf("%d\n", factorial(3));
    printf("%d\n", factorial(4));
    printf("%d\n", factorial(5));
    printf("%d\n", factorial(6));
}