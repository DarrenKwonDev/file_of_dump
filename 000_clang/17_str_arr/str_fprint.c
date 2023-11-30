#include <stdio.h>

int main(void) {
    printf("stdout printf\n");           // stdout
    fprintf(stdout, "fprintf stdout\n"); // file stream

    puts("stdout puts");             // stdout. \n도 넣어줌
    fputs("fputs stdout\n", stdout); // file stream \n 안 넣어줌

    putchar('a');       // stdout
    fputc('b', stdout); // file stream
}