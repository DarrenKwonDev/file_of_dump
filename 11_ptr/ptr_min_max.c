#include <assert.h>
#include <stdio.h>

void get_min_max(int arr[], size_t length, int* min, int* max) {
    assert(arr != NULL);
    assert(length > 1);
    assert(min != NULL);
    assert(max != NULL);

    size_t i;

    *min = arr[0];
    *max = arr[0];

    for (i = 1; i < length; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

int main(void) {
    int nums[5] = {10, 35, 892, 75, 2};
    int min, max;
    get_min_max(nums, 5, &min, &max);
    printf("min: %d, max: %d\n", min, max);
}