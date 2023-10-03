#include <stdio.h>

/*
    https://en.cppreference.com/w/c/io/fread

    size_t fread(
        void *buffer,
        size_t size,
        size_t count,
        FILE *stream );
*/

#define LEN 1024

int main(void) {
    FILE* stream;
    char list[LEN];

    // fopen
    // https://en.cppreference.com/w/c/io/fopen
    stream = fopen("test.txt", "r"); // read mode
    if (stream == NULL) {
        fprintf(stderr, "Failed to open file.\n");
        return 1;
    }

    if (fgets(list, LEN, stream) != NULL) {
        printf("%s", list);
    }

    // fclose는 성공시 0 실패시 EOF를 반환한다.
    if (fclose(stream) != 0) {
        fprintf(stderr, "Failed to close file.\n");
    }

    return 0;
}