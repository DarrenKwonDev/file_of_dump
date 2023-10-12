#include <stdio.h>
#include <stdlib.h>

#define LEN 5

int main(void) {
    int* nums = malloc(sizeof(int) * LEN);

    free(nums);
    free(nums); // wrong!

    return 0;
}