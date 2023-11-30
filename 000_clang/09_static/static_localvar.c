#include <float.h>
#include <stdio.h>

void inc(void) {
    static int cnt = 0;
    int local = 0;
    cnt++;
    local++;
    printf("cnt: %d, local: %d\n", cnt, local);
}

int main(void) {
    // static 지역 변수는 함수가 종료 되어도 메모리에 남아 있어 값을 유지하게 됨.
    // 그러나 일반 지역 변수는 함수가 종료되면서 값도 사라짐.
    inc(); // cnt: 1, local: 1
    inc(); // cnt: 2, local: 1
    inc(); // cnt: 3, local: 1
}