#include <stdio.h>
#include <string.h>

#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

// FIXME: DON'T USE THIS MACRO
// 위험하다. {'a', 'b'}와 같이 null char가 없는 char 배열의 경우 잘못된 결과를 낸다.
#define STR_LENGTH(str) (sizeof(str) / sizeof(str[0]) - 1)

// 이 함수도 위험하다. null char가 없는 char 배열의 경우 잘못된 결과를 낸다.
size_t get_str_len(const char* str) {
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// 이 함수도 위험하다. null char가 없는 char 배열의 경우 잘못된 결과를 낸다.
size_t get_str_len2(const char* str) {
    size_t len = 0;
    const char* p = str; // defensive copy
    while (*p++ != '\0') {
        len++;
    }
    return len;
}

int main(void) {
    char str1[] = "Hello";
    // 모두 null char를 제외한 length를 반환한다.
    printf("%zu\n", get_str_len(str1));
    printf("%zu\n", get_str_len2(str1));
    printf("%zu\n", strlen(str1));
    printf("%lu\n", STR_LENGTH(str1));

    return 0;
}