#include <stdio.h>

int main(void) {
    int num;
    int ch;

    /*
        case 1
        123p를 입력해보자.
    */
    scanf("%d", &num);
    printf("%d\n", num); // 123

    // p는 메모리 버퍼에 남아있음.
    ch = getchar();
    printf("%c\n", ch); // p

    /*
        case 2
        12.34를 입력해보자.
    */
    int num2;
    float f1;
    scanf("%d %f", &num2, &f1);
    printf("%d %.2f", num2, f1); // 12 0.34

    return 0;
}