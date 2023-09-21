#include "counter.h"
/*
    counter.h를 복붙하면서
    extern int g_cnt;
    가 main.c에 선언되는 것과 같아짐.
*/

#include <stdio.h>

extern int g_arr[];

int main(void) {
    size_t i;

    printf("g_cnt = %d\n", g_cnt);
    inc_cnt();
    printf("g_cnt = %d\n", g_cnt);

    for (i = 0; i < 5; i++) {
        printf("g_arr[%lu] = %d\n", i, g_arr[i]);
    }

    return 0;
}