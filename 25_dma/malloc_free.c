#include <stdio.h>
#include <stdlib.h>

/*
    malloc
    https://en.cppreference.com/w/c/memory/malloc
    void* malloc(size_t size);
    size 만큼의 byte를 반환함.
    void* 형을 반환하니 알아서 반환하는 것을 캐스팅해서 사용하라.
    메모리가 부족하면 NULL 반환
*/

#define LEN 3

int main(void) {
    size_t i;
    int* nums = malloc(LEN * sizeof(int));

    for (i = 0; i < LEN; i++) {
        nums[i] = i;
    }

    for (i = 0; i < LEN; i++) {
        printf("%d\n", nums[i]);
    }

    free(nums); // 자원 할당과 해제는 항상 같이 작성.

    return 0;
}