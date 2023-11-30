#include <stdio.h>

#define TRUE (1)
#define FALSE (0)

// https://en.cppreference.com/w/c/io/getchar
int main(void) {
    int c;

    while (TRUE) {
        c = getchar(); // Reads the next character from stdin.
        if (c == EOF) {
            break;
        }
        putchar(c);
    }
    printf("exit. EOF.\n");
    return 0;
}