#include <ctype.h>
#include <stdio.h>
#include <string.h>

/*
    A = 65
    a = 97
    대소문자간 차이는 0x20 (32)
*/

int is_alphabet(int c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int to_upper(int c) {
    if (is_alphabet(c)) {
        // a = 97, A = 65
        // ~는 비트 반전을 의미함.
        // 0b1100001 & ~0b100000 = 65
        return c & ~0x20;
    }
    return c;
}

int to_lower(int c) {
    if (is_alphabet(c)) {
        // 0b1000001 | 0b100000 = 97
        return c | 0x20;
    }
    return c;
}

void string_upper(char* str) {
    while (*str != '\0') {
        *str = to_upper(*str);
        str++;
    }
}

void string_lower(char* str) {
    while (*str != '\0') {
        *str = to_lower(*str);
        str++;
    }
}

int main(void) {
    char a = 'a';
    char A = 'A';
    char str1[] = "Hello, World!";

    printf("%d, %c, %c\n", is_alphabet(a), to_lower(A), to_upper(a));

    string_upper(str1);
    printf("%s\n", str1); // "HELLO, WORLD!"

    string_lower(str1);
    printf("%s\n", str1); // "hello, world!"

    return 0;
}