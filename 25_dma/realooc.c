#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    realloc
    https://en.cppreference.com/w/c/memory/realloc
    void* realloc(void *ptr, size_t new_size);

    이미 존재하는 힙 메모리의 크기를 new_size로 변경.
    가능한 현 데이터는 그대로 유지

    현 사이즈 < new_size인 경우 (늘리는 경우)
    1. new_size를 할당할 공간이 없다면, 아예 새로운 주소를 반환함.
    2. new_size를 할당한 공간이 있어도 컴파일러 구현에 따라 동일 포인터일 수도 아닐 수도.

    현 사이즈 > new_size인 경우 (줄이는 경우)
    1. 어쨌거나 현 데이터는 잘린다.
    2. 컴파일러 구현에 따라 동일한 포인터를 줄 수도, 안 줄 수도 있다.

    결론적으로, realloc을 한다고 했을 때 동일한 포인터를 반환받을 수 있을 지는 모른다
*/

int main(void) {
    void* nums;
    void* tmp;
    nums = malloc(sizeof(int) * 3);

    // 만약에 실패했다고 가정하자. (NULL 반환)
    // 그렇다면 nums는 어떻게 되는 것인가?
    // 해제되지 않고 남아 있다. 그러나 주소는 잃어버렸다. 따라서 메모리 누수가 발생한다.
    tmp = realloc(nums, sizeof(int) * 5);

    // 이를 방지하기 위해 realloc의 반환값은 임시 포인터에 저장하고, null이 아닌 경우에만 포인터에 할당하도록하자.
    if (nums != NULL) {
        nums = tmp;
    }

    /* code */

    // 다 사용한 후 해제
    free(nums);
    nums = NULL;
}