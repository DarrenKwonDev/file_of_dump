#include <stdio.h>

#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

void process(int data[]) {
    // return size of 'int *' instead of 'int[]'s
    // 32bit OS에서는 4byte
    // 64bit OS에서는 8byte
    printf("%lu\n", sizeof(data));
}

// 길이가 명시된 매개변수로서의 배열도 포인터로 취급된다.
// compile하면 int data[]과 같다.
// 배열 길이가 5인 것을 넣어도 컴파일 에러가 나지 않음. 단순히 문서화의 의미만 존재
void process2(int data[20]) {
    printf("%lu\n", sizeof(data));
}

int main(void) {
    int nums[20];
    int nums2[10];

    size_t arr_size = sizeof(nums);
    const size_t arr_cnt = arr_size / sizeof(int);
    const size_t arr_cnt_2 = ARRAY_LENGTH(nums);

    process(nums);
    process2(nums);

    printf("%zu, %zu\n", arr_size, arr_cnt_2);
}