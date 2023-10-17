#include <stdio.h>

int main(void) {
    int arr1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int arr2[3][2] = {{10, 20}, {30, 40}, {50, 60}};

    // 행마다 3개의 원소가 존재하므로 12바이트 차이남.
    printf("%p\n", arr1);
    printf("%p\n", arr1 + 1);
    size_t diff = ((char*)(arr1 + 1) - (char*)arr1);
    printf("arr1 + 1과 arr1의 차: %zu 바이트\n", diff);

    // 행마다 2개의 원소가 존재하므로 8바이트 차이남.
    printf("%p\n", arr2);
    printf("%p\n", arr2 + 1);
    diff = ((char*)(arr2 + 1) - (char*)arr2);
    printf("arr2 + 1과 arr2의 차: %zu 바이트\n", diff);
}