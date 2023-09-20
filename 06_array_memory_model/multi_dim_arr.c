#include <stdio.h>

/*
    3차원이 조금
    [X]
    [X][Y] (x행, y열)
    [Z][X][Y] = (x행, y열)이 Z개 있다. 예를 들어 [2][3][4]는 3행 4열이 2개 있다.
*/

int main(void) {
    int init_table[2][3] = {{1, 2, 3},
                            {4, 5, 6}};
    int table[2][3];
    int one_line_table[2 * 3]; // table과 메모리상으로 같다. 다만 human readable하지 않다.

    /*
        table
        0 1 2
        1 2 3
    */
    for (size_t i = 0; i < 2; i++) {
        for (size_t j = 0; j < 3; j++) {
            table[i][j] = i + j;
            printf("%d\n", table[i][j]);
        }
    }

    printf("============\n");
    /*
        one_line_table
        0 1 2 1 2 3
    */
    for (size_t i = 0; i < 2; i++) {
        for (size_t j = 0; j < 3; j++) {
            one_line_table[i * 3 + j] = i + j;
            printf("%d\n", one_line_table[i * 3 + j]);
        }
    }

    for (size_t k = 0; k < 6; k++) {
        printf("%d\t", one_line_table[k]);
    }

    return 0;
}