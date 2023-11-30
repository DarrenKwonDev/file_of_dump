#include <stdio.h>

/*
    printf
    fprintf
    sprintf
*/

int main(void) {
    printf("stdout printf\n");           // stdout
    fprintf(stdout, "fprintf stdout\n"); // file stream

    return 0;
}