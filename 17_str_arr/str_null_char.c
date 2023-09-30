#include <stdio.h>

/*
    c 스타일 문자열
    = null terminated string
    = 문자열 마지막에 null character(\0)가 존재하는 문자열
*/

#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

int main(void) {
    char str[] = "abcde";        // 배열은 스택 영역에 저장됨.
    char* p_str2 = "abcde";      // 포인터는 스택 영역에 저장되지만 실제 문자열 "abcde"는 데이터 섹션에 저장됩니다.
    char str3 = {"a", "b", "c"}; // 이 경우에는 null char가 들어가지 않는다.

    char null_char = "\0";

    size_t i = 0;

    // 6이 출력됨. null char도 포함되어 카운트 됨.
    printf("%s\t %lu\n", str, ARRAY_LENGTH(str));

    // null char를 제외하고 문자만 출력하려면 len - 1 만큼 반복해야.
    for (i = 0; i < 5; i++) {
        printf("%c\n", *p_str2);
        p_str2++;
    };

    return 0;
}