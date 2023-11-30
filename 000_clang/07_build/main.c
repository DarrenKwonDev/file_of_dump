#include "adder.h"

/*
    add 함수 정의를 include 한 것도 아니고
    함수 선언이 정의된 header를 include했는데 왜 코드가 돌까?
    => 올바른 기능 호출은 linker가 해주기 때문이다.
*/

int main(void) {
    const int res = add(1, 2);
    return 0;
}