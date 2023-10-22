#include <assert.h>
#include <stdio.h>

// num개의 원반. from에 꽂힌 원반을 by를 거쳐 to로 옮긴다.
// 최종 목표는 A에 꽂힌 원반을 B를 거쳐 C에 옮기는 것.
void HanoiTowerMove(int num, char from, char by, char to) {
    if (num == 1) {
        printf("원반 1을 %c에서 %c로 이동\n", from, to);
    } else {
        HanoiTowerMove(num - 1, from, to, by); // num - 1개의 원반을 C를 거쳐 B에 넣음.
        printf("원반 %d를 %c에서 %c로 이동\n", num, from, to);
        HanoiTowerMove(num - 1, by, from, to); // B에 존재하는 num - 1개의 원반을 C에 넣어 탑을 옮김
    }
}

int main(void) {
    HanoiTowerMove(3, 'A', 'B', 'C');
    return 0;
}