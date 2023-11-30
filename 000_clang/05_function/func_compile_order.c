#include <stdio.h>

/*
    접근 제어자 없음 (public, private, protected)
    함수 오버로딩 없음

    C89 컴파일러는 위에서 아래로 코드를 훑음.
    만약 진행 도중 모르는 함수가 호출되었다면 반환형이 int이 함수로 가정함
*/

// 해결 방법 1: foo 함수를 main 전에 위로 올리면 에러를 회피할 수 있음.
// void foo(void) {
//     printf("void foo\n");
// }

// 해결방법 2: 함수 선언을 상단부에 미리 해놓으면 됨.
// 이를 '전방 선언' 이라 함.
// 함수 쓴다면 꼭 전방 선언 해줘라. 좋은 버릇이다.
void foo(void);

int main() {
    foo(); // c compiler가 int 반환하는 함수로 가정하였으나 실제로는 void 반환이라 에러.
    printf("Hello World!\n");
    return 0;
}

void foo(void) {
    printf("void foo\n");
}
