#include <stdio.h>

int main(void) {

    char buffer[50];
    char* p_buf = buffer;
    int n = sprintf(buffer, "%d %s %f", 10, "hello", 3.14);

    // n은 저장된 문자의 총 수를 나타내며, null 문자('\0')는 포함되지 않습니다.
    printf("%d\n", n); // 17 (sprintf는 출력한 문자열의 길이를 반환한다.)
    printf("%s\n", buffer);

    while (*p_buf != '\0') {
        printf("%c ", *p_buf);
        ++p_buf;
    }
    printf("\n");

    return 0;
}