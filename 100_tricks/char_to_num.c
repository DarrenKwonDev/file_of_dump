#include <stdio.h>

int main(void) {
    char c;
    scanf("%c", &c);

    printf("%d\n", c - '0'); // '6' - '0' = 54 - 48 = 6

    return 0;
}