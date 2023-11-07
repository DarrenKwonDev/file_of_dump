#include <assert.h>
#include <stdio.h>

/*
    FILO. LIFO.
    push O(1)
    pop O(1)

    검색 O(2n) : 근본 stack은 push pop만 제공하기 때문에.

    어디에 유리?
    - 후위 표기법
    - 재귀함수 제거
*/

void push(int);
int pop(void);
enum { MAX_NUMS = 8 };

int s_nums[MAX_NUMS];
size_t s_num_count = 0;

int main(void) {
    push(11);
    push(22);
    push(33);

    printf("popped : %d\n", pop());

    // 출력
    printf("bottom\n");
    for (size_t i = 0; i < s_num_count; i++) {
        printf("%d ", s_nums[i]);
    }
    printf("\ntop\n");

    return 0;
}

void push(int n) {
    assert(s_num_count < MAX_NUMS);
    s_nums[s_num_count++] = n;
}

int pop(void) {
    assert(s_num_count > 0);
    return s_nums[--s_num_count];
}

// push와 pop만 존재하는게 stack의 기본형태
// 따라서 stack에서의 검색은 제거해가면서 찾고, 찾은 후에는 원상 복구해야 함.
// 따라서 제거에 O(n) 복구에 O(n)이 필요해 O(2n)이 필요함.
// 구현은 알아서 해 볼 것.