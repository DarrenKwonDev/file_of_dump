#include <stdio.h>

/*
    1의 보수 : 비트 반전
    2의 보수 : 1의 보수 + 1

    2의 보수 = 음수 표현
*/

int main(void) {
    int num;
    scanf("%d", &num);

    // 1의 보수 계산 (~)
    int onesComplement = ~num;

    // 2의 보수 계산 (1의 보수에 1을 더함)
    int twosComplement = onesComplement + 1;

    printf("Original Number: %d\n", num);
    printf("One's Complement: %d\n", onesComplement);
    printf("Two's Complement: %d\n", twosComplement);

    return 0;
}