#include <stdio.h>
#include <string.h>

int main(void) {
    char str[] = "Money, Wow. Hello!";
    char delims[] = " ,. !";

    char* token = strtok(str, delims); // 토큰화 시작
    printf("%s\n", token);

    token = strtok(NULL, delims); // 다음 토큰 탐색
    printf("%s\n", token);

    token = strtok(NULL, delims);
    printf("%s\n", token);

    token = strtok(NULL, delims);
    printf("%s\n", token);

    // str내 포함된 delims들이 \0로 치환된다. 즉, strtok는 원본 문자열을 수정한다.
    // Money\0 Wow\0 Hello\0
    printf("%s\n", str); // 첫 \0을 만나기 전까지만 출력하므로 Money만 출력된다.

    /*
        while로 모두 처리하기
    */
    // char* token = strtok(str, delims);
    // printf("%s\n", token);
    // while (token != NULL) {
    //     token = strtok(NULL, delims);
    //     printf("%s\n", token);
    // }

    return 0;
}