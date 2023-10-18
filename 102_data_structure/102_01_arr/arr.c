#include <assert.h>
#include <stdio.h>

enum { MAX_NUMS = 8 };
enum { INVALID_INDEX = -1 };

void insert_at(size_t index, int n);
void remove_at(size_t index);
size_t find_index(int n);

int s_nums[MAX_NUMS];
size_t s_nums_count = 0;

/*
    삽입 O(n)
    삭제 O(n)
    탐색 O(n)
    접근 O(1)
*/
int main() {
    insert_at(0, 1);
    insert_at(0, 2);
    insert_at(0, 3);
    insert_at(0, 4);
    insert_at(0, 5);
    insert_at(0, 6);
    insert_at(0, 7);
    insert_at(7, 8);

    // {7, 6, 5, 4, 3, 2, 1, 8}

    remove_at(7);
    remove_at(0);
    remove_at(0);
    // {5, 4, 3, 2, 1}

    printf("%zu\n", find_index(3)); // 2
    printf("%zu\n", find_index(7)); // -1

    // 출력
    printf("----출력----\n");
    for (size_t j = 0; j < s_nums_count; j++) {
        printf("%d\n", s_nums[j]);
    }

    return 0;
}

void insert_at(size_t index, int n) {
    size_t i;
    assert(index <= s_nums_count);   // 현재 존재하는 원소 개수보다 큰 인덱스는 삽입 불가능
    assert(s_nums_count < MAX_NUMS); // 이미 배열 꽉 찼다면 못 넣는다.

    // 넣으려는 곳을 뒤로 미룬다.
    // 현재 3개 차 있는데 넣으려는 곳은 1이라고 가정하자.
    // [1 2 3] 그러면 2, 3은 뒤로 한 칸씩 이뤄야 한다.
    // 맨 뒤부터 넣고자하는 index까지 한 칸씩 뒤로 밀어야 한다.
    for (i = s_nums_count; i > index; --i) {
        s_nums[i] = s_nums[i - 1];
        // s_num[1] = s_num[0]; 즉 뒤로 한 칸 밀림.
    }

    s_nums[index] = n;
    ++s_nums_count;
}

void remove_at(size_t index) {
    size_t i;

    assert(index < s_nums_count); // 현재 있는 원소 갯수보다 큰 인덱스는 삭제 불가능

    --s_nums_count;

    // [1 2 3 4 5 6 7 8] 가정.
    // 3번째 인덱스를 지우려고 한다.
    // 3에서 8까지 1씩 증가하며 앞으로 당겨야 한다.
    // 즉, 4번째 원소가 3번째 원소가 되는 식.
    for (i = index; i < s_nums_count; i++) {
        s_nums[i] = s_nums[i + 1];
        // s_nums[0] = s_nums[1];
        // 즉, 앞의 원소를 앞으로 한 칸 당겨온다.
    }
}

size_t find_index(int n) {
    size_t i;

    for (i = 0; i < s_nums_count; i++) {
        if (s_nums[i] == n) {
            return i;
        }
    }

    return INVALID_INDEX;
}