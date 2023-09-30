#include <ctype.h>
#include <stdio.h>
#include <string.h>

/*
    구현 목표

    같으면 0
    str1이 더 크면 > 0 (반드시 1일 필요는 없음)
    str1이 더 작으면 < 0 (반드시 -1일 필요는 없음)
*/

int compare_str1(const char* str1, const char* str2) {
    size_t i = 0;
    while (1) {
        if (str1[i] == '\0' && str2[i] == '\0') {
            return 0;
        } else if (str1[i] == '\0') {
            return -1;
        } else if (str2[i] == '\0') {
            return 1;
        } else if (str1[i] > str2[i]) {
            return 1;
        } else if (str1[i] < str2[i]) {
            return -1;
        }
        i++;
    }
}

int compare_str2(const char* str1, const char* str2) {

    // 둘다 \0인 경우는 이미 첫 조건에서 걸러져서 나옴.
    while (*str1 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }

    // while을 통과한 경우
    // *str1이 끝났다 (null char를 만난 경우)
    // or
    // *str1이 *str2 다른 경우
    return *str1 - *str2;
}

int compare_str3(const char* str1, const char* str2) {
    while (*str1 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }

    if (*str1 == *str2) {
        return 0;
    }

    return *str1 > *str2 ? 1 : -1;
}

int compare_case_insensitive_str(const char* str1, const char* str2) {
    int c1, c2;
    c1 = tolower(*str1);
    c2 = tolower(*str2);
    while (c1 != '\0' && c1 == c2) {
        c1 = tolower(*++str1);
        c2 = tolower(*++str2);
    }
    if (c1 == c2) {
        return 0;
    }
    return c1 > c2 ? 1 : -1;
}

int main(void) {
    char str1[] = "Hello";
    char str2[] = "Hello";
    char str3[] = "Hello!";
    char str4[] = "Hell";
    char str5[] = "HeLlO";

    printf("%d\n", compare_str1(str1, str2));
    printf("%d\n", compare_str1(str1, str3));
    printf("%d\n", compare_str1(str1, str4));

    printf("===\n");

    printf("%d\n", compare_str2(str1, str2));
    printf("%d\n", compare_str2(str1, str3));
    printf("%d\n", compare_str2(str1, str4));

    printf("===\n");

    printf("%d\n", compare_str3(str1, str2));
    printf("%d\n", compare_str3(str1, str3));
    printf("%d\n", compare_str3(str1, str4));

    printf("===\n");

    // 내장 함수
    printf("%d\n", strcmp(str1, str2));
    printf("%d\n", strcmp(str1, str3));
    printf("%d\n", strcmp(str1, str4));

    printf("===\n");
    printf("%d\n", compare_case_insensitive_str(str1, str5));

    return 0;
}