#include <stdio.h>

#define TRUE (1)
#define FALSE (0)
#define LINE_LENGTH (10)

int main(void) {
    char line[LINE_LENGTH]; // 최대 9글자까지만 읽음. 마지막은 \0

    if (fgets(line, LINE_LENGTH, stdin) != NULL) {
        printf("%s", line); // buffer를 초과해도 LINE_LENGTH - 1까지만 읽음.
    }

    printf("\n flush time! \n");
    fflush(stdin); // why? 안 비우면 다음 입력은 남아 있는 stdin을 처리하기 위해 자동으로 들어감.

    // fflush 하지 않으면 stdin에 남아 있는 내용물을 출력하려 한다.
    // fflush를 주석처리하고 '1234567891011'를 입력하면 아래 코드에서 1011을 출력한다.
    if (fgets(line, LINE_LENGTH, stdin) != NULL) {
        printf("%s", line); // buffer를 초과해도 LINE_LENGTH - 1까지만 읽음.
    }

    return 0;
}