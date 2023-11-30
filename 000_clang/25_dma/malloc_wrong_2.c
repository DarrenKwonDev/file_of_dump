#include <stdio.h>
#include <stdlib.h>

#define LEN 5

int main(void) {
    int* pa_nums = malloc(sizeof(int) * LEN);

    free(pa_nums);
    free(pa_nums); // wrong!

    return 0;
}