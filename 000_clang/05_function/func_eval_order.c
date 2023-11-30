#include <stdio.h>

/*

unspecified behavior
- 컴파일러 구현에 따라 결과가 달라짐.


한 줄에 함수 호출을 여러 번 쓰지 말아라.
func1() + func2()과 같은 경우 어느 함수가 먼저 평가될 지 알 수 없음. 컴파일러 구현에 따라 다름.
대신에 여러 줄에 나눠 순차적으로 출력하도록 만들어라.
*/

/*
undefined behavior
- 결과 자체가 결정적이지 않다. 따라서 코드 동작이 비결정적이게 되고 위험하게 된다.

한 줄에서 동일한 변수를 바꾸면 위험하다.
아래와 같은 코드들은 다 위험한 것들이다.
func(++i, ++i)
func(i = -1, i = -1)
func(i, i++)
int num = ++num + num++

*/

float divider(int a, int b) {
    printf("%d, %d\n", a, b);
    return a / (float)b;
}

int main(void) {
    int num = 0;
    // undefined behavior
    // 왜냐하면 앞의 ++num이 먼저 평가될지, 뒤의 ++num이 먼저 평가 될 지 모르기 때문
    printf("%f\n", divider(++num, ++num));

    return 0;
}