#include "counter.h"

int g_cnt = 0;
int g_arr[5] = {};

void inc_cnt(void) {
    g_cnt++;
    g_arr[g_cnt % 5] = g_cnt;
}