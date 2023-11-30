#include <assert.h>
#include <stdio.h>

void raise_assertion_err(int* ptr_or_null) {
    // null이 들어올 수 있는 param이라면 or_null 접미사를 붙이는 것이 좋다.

    // 가급적 assert, early return으로 가능성을 좁히는 것이 좋다.
    assert(ptr != NULL); // ptr이 NULL이면 프로그램 종료
}

// 함수에서도 null을 반환할 수 있다면 함수 이름에 or_null 접미사를 붙이자.
int* get_num_or_null(const int num) {
    return NULL;
}

int main(void) {
    int* p_num;

    // #define __DARWIN_NULL ((void *)0)
    // 즉, void * 형태로 캐스팅 된 0. 숫자 0이 아님.
    // NULL ptr를 작성하면 존재하지 않는 주소 0을 가리킴
    p_num = NULL; // 0을 대입해도 됨

    if (p_num == NULL) {
        printf("ptr is null ptr\n");
    }
    if (p_num == 0) {
        printf("ptr is null ptr\n");
    }

    return 0;
}