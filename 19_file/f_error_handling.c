#include <errno.h>
#include <stdio.h>
#include <string.h>

/*
    errno
    https://en.cppreference.com/w/cpp/error/errno
    에러 넘버만 주지 구체적으로 무슨 문제인지는 말 안 해줌.

    strerror(errno)를 통해서 에서 메세지를 확인할 수 있음.
    https://en.cppreference.com/w/c/string/byte/strerror

    perror
    https://en.cppreference.com/w/c/io/perror
*/

int main(void) {
    FILE* stream;

    stream = fopen("no_file.txt", "r+"); // r+ mode for raise error
    if (stream == NULL) {
        fprintf(stderr, "errno. [%d]. %s\n", errno, strerror(errno));
        perror(""); // strerror(errno)를 줄력해줌
        return 1;
    }
}