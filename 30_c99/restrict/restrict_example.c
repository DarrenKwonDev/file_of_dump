#include <stdio.h>

/*
    restrict 선언된 포인터 변수들은 메모리 겹침이 일어나지 않을 것이라 컴파일러에게 힌트를 줌.
    컴파일러 단에서의 최적화 일부 발생.
*/
void array_add(int* restrict dest,
               const int* restrict arr1,
               const int* restrict arr2,
               size_t size) {
    size_t i;
    for (i = 0; i < size; ++i) {
        dest[i] = arr1[i] + arr2[i];
    }
}

int main() {
    int dest[5];
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {5, 4, 33, 12, 1};
    array_add(dest, arr1, arr2, 5);

    for (size_t j = 0; j < 5; j++) {
        printf("%d ", dest[j]);
    }

    return 0;
}
