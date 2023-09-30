#include <stdio.h>
#include <string.h>

int main(void) {
    char str[] = "oh my oh my god, 예상했던 결과가 나오지 않네요.";
    char* res = strstr(str, "way");             // return null pointer
    printf("%s\n", res == NULL ? "null" : res); // null

    char* res2 = strstr(str, "예상"); // 찾은 위치부터 시작하는 전체 문자열을 가리키는 ptr
    printf("%p\n", res2);
    printf("%zu\n", (size_t)(res2 - str));        // 17. 찾은 위치의 index
    printf("%s\n", res2 == NULL ? "null" : res2); // "예상했던 결과가 나오지 않네요."

    return 0;
}