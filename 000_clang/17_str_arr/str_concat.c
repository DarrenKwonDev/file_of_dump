#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    const char* src = "World";
    char dest[12] = "Hello ";

    strcat(dest, src);
    // strncat(dest, src, 5);

    printf("%s\n", dest);          // "Hello World"
    printf("%lu\n", strlen(dest)); // "Hello World"

    return 0;
}