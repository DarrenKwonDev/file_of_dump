#include <stdio.h>
#include <stdlib.h>

#define LEN 5

// malloc으로 받아온 최초의 주소를 연산에 사용하지 말아라. free의 대상이 유효하지 않게 된다.
// 가급적이면 해당 주소를 복사해서 사용하라.

int main(void) {
    int* nums = malloc(sizeof(int) * LEN);
    printf("initial: %p\n", nums);
    for (size_t i = 0; i < LEN; i++) {
        // 역참조로 대입 후 포인터 이동.
        *nums++ = i;
    }

    printf("after: %p\n", nums);

    // pointer being freed was not allocated
    free(nums); //  wrong!
    return 0;
}