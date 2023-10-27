#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    // 10의 자리까지 내림, 반올림, 올림
    int floor_down = (n / 10) * 10;
    int round_up = ((n + 5) / 10) * 10;
    int ceil_up = ((n + 9) / 10) * 10;

    printf("%d %d %d\n", floor_down, round_up, ceil_up);

    return 0;
}