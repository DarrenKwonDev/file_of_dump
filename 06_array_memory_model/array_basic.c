#include <stdio.h>

int main(void) {
    int nums[5] = {1, 2, 3, 4, 5};
    int avg = 0;
    int i;

    for (i = 0; i < 5; i++) {
        avg += nums[i];
    }
    avg /= i;

    printf("avg = %d\n", avg);

    return 0;
}