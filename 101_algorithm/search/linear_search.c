#include <stdio.h>

enum {
    NOT_FOUND = -1
};

size_t linear_search(int arr[], int len, int target) {
    size_t idx = NOT_FOUND;

    for (size_t i = 0; i < len; i++) {
        if (arr[i] == target) {
            idx = i;
            break;
        }
    }

    return idx;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    size_t idx = linear_search(arr, sizeof(arr) / sizeof(int), 3);

    if (idx == NOT_FOUND) {
        printf("Not found\n");
    } else {
        printf("Found at %zu\n", idx);
    }

    return 0;
}
