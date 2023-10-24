#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int main() {
    // 한국어 변수
    int 숫자 = 3;
    printf("%d\n", 숫자);

    // char type 크기인 1 byte를 초과함.
    // ''는 단일 바이트 문자만을 나타낼 수 있으므로 ""를 사용해야 함.
    // 즉, 문자열 처럼 취급해야 함.
    // char ch1 = '코'; // character too large for enclosing character literal type

    // 문자열로써 다루기.
    char* ch2 = "코";
    char ch3[] = "코";
    char* ch4 = "\ucf54"; // 코

    printf("%s\n", ch2);
    printf("%s\n", ch3);
    printf("%s\n", ch4);

    printf("%lu byte\n", sizeof(ch2)); // ptr의 크기
    printf("%lu byte\n", sizeof(ch3)); // 문자열의 크기
    printf("%lu byte\n", sizeof(ch4)); // ptr의 크기

    // 와이드 문자열
    // 사용하는 운영 체제 와 설정에 따라 출력이 안 될 수도 있음
    wchar_t* wide_char = L"힝";
    printf("%ls\n", wide_char); // 와이드 문자열을 멀티바이트 문자열로 반환.
    wprintf(L"%ls\n", wide_char);

    return 0;
}