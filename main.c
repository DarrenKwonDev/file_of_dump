#include <stdio.h>

#define LINE_LEN 1024

/*
    size_t fread(
        void *buffer,
        size_t size,
        size_t count,
        FILE *stream );
*/
int main(void) {
    char str[10] = "1234567890";
    *str += 5;
    printf("%c\n", *str);
}