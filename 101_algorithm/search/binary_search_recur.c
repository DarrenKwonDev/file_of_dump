#include <assert.h>
#include <stdio.h>

enum {
    NOT_FOUND = -1
};

size_t binary_search_recur(int sorted_arr[], int left, int right, int target) {

    if (left > right) {
        return NOT_FOUND;
    }

    int cursor = (left + right) / 2;
    printf("%d %d %d\n", left, right, cursor);

    if (sorted_arr[cursor] == target) {
        return cursor;
    } else if (sorted_arr[cursor] > target) {
        return binary_search_recur(sorted_arr, left, cursor - 1, target);
    } else {
        return binary_search_recur(sorted_arr, cursor + 1, right, target);
    }

    return NOT_FOUND;
};

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    size_t idx = binary_search_recur(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);

    if (idx == NOT_FOUND) {
        printf("not found\n");
    } else {
        printf("Found at: %zu\n", idx);
    }

    return 0;
}
