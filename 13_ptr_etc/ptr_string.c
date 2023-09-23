#include <stdio.h>

int main(void) {
    // "Hello" 문자는 data section에 있다가
    // 함수 내에서 사용할 때에 stack에 복사되어 사용됨.
    char str1[] = "Hello";

    // "Hello" 문자는 data section에 있다가
    // 함수 내에서 사용할 때에 stack에는 포인터만 복사되어 사용됨.
    // 즉  여기서 수정을 가하면 data section의 원본 문자 배열을 조작하는 것임
    char* str2 = "Hello";

    str1[0] = 'A'; // stack에 존재하는 복사하는 값은 변경 가능
    str2[0] = 'A'; // error. 데이터 영역의 값을 변경할 수 없음.

    return 0;
}