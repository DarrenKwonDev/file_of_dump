#include <stdio.h>

/*
    memory stomp : 남의 메모리 영역을 침범해서 조작하는 것.
*/

int main(void) {
    int notIntended[2] = {1, 1};
    int a2[2] = {2, 2};
    size_t i;

    // i < 2가 맞으나 의도적으로 memory stomp를 보여주기 위해서 <=로 작성.
    for (i = 0; i <= 2; i++) {
        a2[i] = 0;
    }

    for (i = 0; i < 2; i++) {
        printf("%d\n", notIntended[i]); // 의도치 않은 배열에 영향이 가버렸음.
        printf("%d\n", a2[i]);
    }

    return 0;
}