// 고수준 언어의 아름다운 모듈 import 시스템이 아니다.
// 전처리기가 stdio.h의 내용을 단순히 붙여넣는 방식으로 작동한다.
#include <stdio.h> // standard input output header file

int main(void) { // 함수 정의에서 인자가 없으면 명시적으로 void를 적어야 한다.
    printf("Hello, %s\n", "World!"); // format print
    return 0; // process exit code. 'echo $?'로 확인 가능
}