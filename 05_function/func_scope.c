#include <stdio.h>

/*
    block scope -> {} 내 변수
    file scope -> 전역 변수
    function scope -> label(goto) 정도에서만 사용
    function prototype scope -> void func(int val, char array[10 * sizeof(val)]) 과 같이 함수 () 안에서만 사용
*/

// file scope
// memory 상에서 데이터 영역에 존재. 전역 변수.
int g_num = 235;

int main(void) {
    int a = 3;
    printf("%d\n", a);

    { // block scope
        int b = 4;
        int a = 5;            // variable shadowing. 하지 말아라.
        g_num = g_num + 1000; // mutate global var
        printf("%d, %d\n", a, b);
        // block scope 벗어나면 내부 변수들 수거됨. 외부 접근 불가.
    }

    printf("%d\n", a);
    // printf("%d\n", b); // error: use of undeclared identifier 'b'

    printf("%d\n", g_num);

    return 0;
}