#include <stdio.h>
#include <string.h>

void copy_string(char* dest, const char* src) {
    while (*src != '\0') {
        // 역참조 먼저하고 포인터를 증가 시킴.
        *dest++ = *src++;
    }

    // 마지막에 null char
    *dest = '\0';
}

int main(void) {
    const char* str1 = "Hello";
    char str2[6]; // 5글자 + null char
    char str3[6];
    char str4[] = "zzzzzzzz";

    copy_string(str2, str1);
    strcpy(str3, str1); // 위의 함수와 같은 동작을 하는 함수 (string.h

    printf("%s\n", str2);
    printf("%s\n", str3);

    strncpy(str4, str1, 4); // 3글자만 복사
    printf("%s\n", str4);   // Hellzzzzzz

    return 0;
}