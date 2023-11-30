#include <stdio.h>

/*
    fwrite
    https://en.cppreference.com/w/c/io/fwrite

    size_t fwrite(
        const void *buffer,
        size_t size,
        size_t count,
        FILE *stream );
*/

#define LEN 12

int main(void) {
    FILE* stream;
    char buffer[1024];
    char str[LEN] = "Hello World!";

    stream = fopen("test.txt", "w"); // write mode

    fwrite(str, sizeof(char), LEN, stream);
    fflush(stream); // 곧 바로 쓰기 위하여

    stream = fopen("test.txt", "r"); // read mode
    while (1) {
        // 그냥 내 맘대로 3자씩 끊어 읽기로 함.
        // 마지막에는 \0를 넣어주므로 보이는 건 문자 2개씩 일 것임.
        if (fgets(buffer, 3, stream) == NULL) {
            break;
        }
        printf("%s | ", buffer);
    }

    return 0;
}