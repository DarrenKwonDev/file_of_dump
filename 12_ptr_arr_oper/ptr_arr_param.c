#include <stdio.h>

size_t ret_ptr_arr_param_size(int arr[]) {
    // 연속된 메모리 상에 위치한 arr의 첫 주소를 가리키는 포인터를 반환.
    return sizeof(arr); // sizeof on array function parameter will return size of 'int *' instead of 'int[]'
}

#define LENGTH 100

int main(void) {
    int a = 3;
    int* p_a = &a;
    int nums[LENGTH] = {
        0,
    }; // 전부 0으로 초기화

    printf("%lu\n", sizeof(p_a));                  // 8byte
    printf("%zu\n", ret_ptr_arr_param_size(nums)); // 8byte
    return 0;
}