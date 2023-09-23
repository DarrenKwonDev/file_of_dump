#include <stdio.h>

void print_all_array(int* const arr[], const size_t outerLen, const size_t eachArrLen[]) {
    size_t i, j;
    const int* p; // 값 보호 포인터

    for (i = 0; i < outerLen; i++) {
        for (j = 0; j < eachArrLen[i]; j++) {
            p = arr[i] + j;
            printf("%d ", *p);
        }
        printf("\n");
    }
}

int main(void) {
    int nums1[] = {1, 2, 3};
    int nums2[] = {10, 33, 99, 55};
    int nums3[] = {1356};

    // int* 자료형을 담고 있는 배열 선언.
    int* ptr_arr[3] = {nums1, nums2, nums3};

    // 일부 출력
    printf("%d %d %d\n", *(ptr_arr[0] + 2), ptr_arr[1][3], *ptr_arr[2]);

    // 모두 출력
    print_all_array(ptr_arr, 3, (size_t[]){3, 4, 1});

    return 0;
}
