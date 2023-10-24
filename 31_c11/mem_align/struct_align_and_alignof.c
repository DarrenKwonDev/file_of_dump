#include <stdalign.h>
#include <stdio.h>
#include <stdlib.h>

// 멤버 변수 모두 정렬
typedef struct data {
    alignas(4096) int num;
    alignas(1024) int dummy[10];
} data_t;

// C와 Cpp가 다름.
// C에선 최하단 멤버 변수만 정렬하면 모든 멤버 변수가 1024 정렬이 됨.
// 헷갈리니 그냥 하나씩 다 적어주는게 낫다.
typedef struct data2 {
    int num;
    alignas(1024) int dummy[10];
} data2_t;

int main(void) {
    alignas(4096) data_t data = {
        0,
    }; // 선언 시 struct 자체도 align 가능

    // 사이즈가 4096임. align 해야 해서 메모리 공간 많이 잡아 먹음. 어쩔 수 없음...
    // align 안 했다면 4 + 10 * 4 = 44 바이트 정도일 것임.
    printf("size of struct: %lu\n", sizeof(data));

    printf("is struct aligned? : %lu\n", (size_t)&data % 4096);
    printf("is num aligned? %lu\n", (size_t)&data.num % 4096);
    printf("is data dummy aligned? %lu\n", (size_t)&data.dummy % 1024);
    return 0;
}