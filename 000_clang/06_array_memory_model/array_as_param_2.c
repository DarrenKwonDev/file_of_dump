#include <stdio.h>

#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

// 매개 변수 배열의 cnt(원소 갯수)를 함수가 알 수 있는 방법이 없다.
// 즉, 배열의 원소 갯수는 따로 기억해야 한다.
void process(size_t n, int nums[]) {
    size_t i;
    for (i = 0; i < n; i++) {
        printf("%d\n", nums[i]);
    }
}

int main(void) {
    int nums[5] = {1, 2, 3, 4, 5};
    process(ARRAY_LENGTH(nums), nums);
    return 0;
}