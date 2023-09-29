#include <stdio.h>

#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

int main(void) {
    char str[] = "abcde";
    printf("%s\t %lu\n", str, ARRAY_LENGTH(str));
    return 0;
}