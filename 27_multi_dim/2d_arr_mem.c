#include <stdio.h>

int main(void) {
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

    // 2차원 배열이나 메모리는 순차적으로 (1차원적으로) 저장됨.
    for (size_t i = 0; i < 2; i++) {
        for (size_t j = 0; j < 3; j++) {
            printf("%p\n", &arr[i][j]);
        }
    }

    return 0;
}