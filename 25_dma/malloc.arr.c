#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 3
#define BUFF_LEN 256

int main(void) {
    char* lines[LEN];
    char buff[BUFF_LEN];
    size_t i;

    for (i = 0; i < 3; i++) {
        if (!fgets(buff, sizeof(char) * BUFF_LEN, stdin)) {
            printf("fgets error\n");
            return 1;
        }

        // buff에 입력된 string 만큼의 길이만큼 동적 배열을 생성.
        lines[i] = malloc(strlen(buff) + 1); // +1 for '\0'
        if (!lines[i]) {
            printf("malloc error\n");
            return 1;
        }

        strcpy(lines[i], buff); // buff의 값을 lines[i]에 복사.
    }

    for (i = 0; i < 3; i++) {
        printf("%s", lines[i]);
    }

    return 0;
}