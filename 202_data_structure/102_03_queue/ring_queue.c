#include <assert.h>
#include <stdio.h>
/*
    FIFO, LILO
    enqueue O(1) 단, 링큐일 경우.
    dequeue O(1) 단, 링큐일 경우.
    검색은 O(2n). 스택과 마찬가지로 하나씩 빼면서 찾고 원상 복구해야 함.

    배열로 대충 구현하면 O(n)이 됨.
    1. enqueue가 맨 앞이면 deque할 때 다 땡겨와야 함.
    [1, 2] -> [2]. 즉, 지우고 땡겨와야. 지울 때 O(n)임
    2. enqueue가 맨 뒤면 dequeue할 때 맨 앞만 땡겨오면 됨.
    [2, 1] -> [2]. 그냥 뒤를 지우면 되지만 enqueue가 O(n)임

    큐의 두 동작을 O(1)으로 만드려면 ring buffer를 사용해야 함.
    어느 위치든 시작과 끝이 될 수 있음.

    ring queue 구현의 핵심은
    enqueue할 때 s_back을 이동시키고,
    dequeue할 때 s_front를 이동시키는 것.
*/

enum { MAX_NUMS = 8 };

void enqueue(int);
int dequeue(void);

int s_nums[MAX_NUMS];

// 의도
// 넣을 때 s_back을 이동시키고, 뺄 때 s_front를 이동시킴.
size_t s_front = 0;
size_t s_back = 0;
size_t s_num_count = 0;

int main(void) {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(70);
    enqueue(80);

    dequeue();
    dequeue();

    for (size_t i = 0; i < s_num_count; i++) {
        printf("%d -> ", s_nums[i]);
    }
    printf("\n");

    return 0;
}

void enqueue(int n) {
    assert(s_num_count < MAX_NUMS);

    s_nums[s_back] = n;

    // s_back의 위치를 이동시킵니다.
    s_back = (s_back + 1) % MAX_NUMS;
    // 위 연산을 설명하자면, ring buffer. 되돌아오는 연산.
    // 현재 배열 크기 8로 잡아놨음.
    // 7번째 인덱스가 들어오는 순간 s_back은 0이 됨.
    // 따라서 8번째 값이 들어오면 배열의 첫 자리를 덮어쓰게 됨. (이건 assert로 일단 막아놨다.)

    ++s_num_count;
}

int dequeue(void) {
    int ret;

    assert(s_num_count > 0);

    // 맨 앞의 값을 반환합니다.
    ret = s_nums[s_front];

    --s_num_count;

    // 값을 지웠으니 s_front를 이동시킵니다.
    s_front = (s_front + 1) % MAX_NUMS;

    return ret;
}
