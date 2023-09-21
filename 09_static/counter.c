#include "counter.h"

static int s_cnt = 0; // 이 static 변수는 counter.c에서만 접근 가능

void inc_cnt(void) {
    static int s_inner_cnt = 0; // 함수 내 static 변수는 함수가 끝나도 GC되지 않음.
    s_cnt++;
    s_inner_cnt++;
}