#include <stdio.h>

/*
    goto가 악마는 아니다. 유용한 경우가 몇 경우가 있다.

    1. goto는 언제나 아래로만 jump할 것
    2. 협업자들이 싫어하면 그냥 쓰지 말 것.
*/

int main(void) {
    const int HEIGHT = 10;
    const int WIDTH = 10;
    const int DEPTH = 10;

    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            for (k = 0; k < DEPTH; k++) {
                printf("i = %d, j = %d, k = %d\n", i, j, k);
                if (k == 2) {
                    goto loop_exit;
                    // break는 현재 for문만 빠져나온다.
                    // 따라서 모든 for문을 벗어나기 위해서는 goto를 사용하는 것이 코드를 간결하게 유지하는데 도움된다.
                    // 이게 안되는 언어는 bool 변수를 flag 처럼 사용하여 다 돌았는지를 체크하도록 만들어야 한다.
                }
            }
        }
    }

loop_exit:
    printf("loop exit\n");

    return 0;
}
