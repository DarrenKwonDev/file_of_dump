#include <stdio.h>

#define LINE_LEN 1024

int main(void) {
    int sum = 0;
    int num;
    char line[LINE_LEN];

    while (1) {
        // 한 줄 읽고
        if (fgets(line, LINE_LEN, stdin) == NULL) {
            clearerr(stdin);
            break;
        }

        // 한 줄에서 숫자를 읽어낸다.
        if (sscanf(line, "%d", &num) == 1) {
            sum += num;
        }
    }

    printf("sum: %d\n", sum);
}