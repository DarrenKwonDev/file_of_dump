#include <stdio.h>

/*
    rewind
    https://en.cppreference.com/w/c/io/rewind
*/
int main(void) {
    FILE* stream;
    char line[256];

    stream = fopen("test.txt", "r");

    // error handle omit

    while (1) {
        if (fgets(line, 256, stream) == NULL) {
            break;
        }
        printf("%s\n", line);
    }

    rewind(stream);

    while (1) {
        if (fgets(line, 256, stream) == NULL) {
            break;
        }
        printf("%s\n", line);
    }

    fclose(stream);
}