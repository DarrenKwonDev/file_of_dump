#include <stdio.h>

int main(void) {
    int nums[5] = {8, 1, 7, 0, 50};
    int* ptr1 = nums;
    int* ptr5 = nums + 4;

    // 포인터 간에는 '뺄셈'만 가능.
    // 뺄셈의 결과는 두 포인터가 가리키는 주소의 차이를 반환.
    // 즉, 사이에 몇 개의 원소가 더 추가될 수 있는가.
    // 즉 `마지막 ptr - 최초 ptr + 1 = 배열의 길이`
    int ptr_sub = ptr5 - ptr1;

    printf("%d\n", ptr_sub); // 4

    return 0;
}