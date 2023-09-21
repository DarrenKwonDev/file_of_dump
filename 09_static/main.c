#include "counter.h"
#include <stdio.h>

// extern int s_cnt; // extern을 쓰더라도 static 변수는 접근 불가
// error : Undefined symbols

int main(void) {
    inc_cnt();
    // printf("gs_cnt = %d\n", s_cnt);
    return 0;
}