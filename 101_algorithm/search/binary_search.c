#include <assert.h>
#include <stdio.h>

enum {
    NOT_FOUND = -1
};

size_t binary_search(int sorted_arr[], int len, int target) {
    int left = 0;
    int right = len;
    int cursor = NOT_FOUND;

    while (left <= right) {
        cursor = (left + right) / 2;

        if (sorted_arr[cursor] == target) {
            return cursor;
        }
        if (sorted_arr[cursor] > target) {
            // target이 왼쪽에 있으므로 right를 cursor - 1로 조정
            right = cursor - 1;
        } else if (sorted_arr[cursor] < target) {
            // target이 오른쪽에 있으므로 left를 cursor + 1로 조정
            left = cursor + 1;
        }
    }

    return cursor;
};

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    size_t idx = binary_search(arr, sizeof(arr) / sizeof(int), 7);

    if (idx == NOT_FOUND) {
        printf("not found\n");
    } else {
        printf("Found at: %zu\n", idx);
    }

    return 0;
}
