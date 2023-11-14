#include <stdio.h>

int main(void) {
    char c;
    scanf("%c", &c);

    // char to num
    printf("%d\n", c - '0'); // '6' - '0' = 54 - 48 = 6

    // num to char
    printf("%d\n", 5 + '0'); // '6' + '0' = 54 + 48 = 102

    return 0;
}