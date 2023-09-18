#include <stdio.h>

/*
if, switch는 조건문
for, while은 반복문

break, continue는 반복문을 제어하는 것이지 조건문에서 벗어나기 위한 것이 아님.
while () {
    if (조건) {
        break; // 여기 break는 while을 탈출 한다.
    }
}
*/

int main(void)
{
    size_t i = 0;
    size_t j = 0;

    // for loop
    for (i = 0; i < 3; i++) {
        printf("%lu\n", i);
    }

    printf("after exit for loop %lu\n", i);

    // while
    while (i++ < 4) { // 이 행이 평가된 후에 후위 연산 적용.
        printf("%lu\n", i);
    }

    printf("after exit while loop %lu\n", i);
    printf("====================================\n");

    // break, continue
    for (j = 0; j < 10; j++) {
        if (j == 2) {
            continue; // skip
        }
        if (j == 4) {
            printf("break loop");
            break; // exit loop
        }

        printf("%lu\n", j);
    }

    return 0;
}