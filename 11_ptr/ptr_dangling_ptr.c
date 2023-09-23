#include <stdio.h>

/*
    -   dangling ptr
        -   함수 내 지역변수가 존재하는 stack frame은 함수가 return되면 방치 된다. 추후 동작에 따라서 해당 메모리는 다른 것이 덮어 쓰게 된다.
        -   따라서 함수는 포인터 변수를 반환하면 안된다. 유효하지 않은 주소를 반환하기 때문이다.
*/

int* ret_dangling_ptr(const int a, const int b) {
    int sum = a + b;

    // address of stack memory associated with local variable 'sum' returned
    // 함수 반환 후 stack frame은 방치된다. 즉, 유효한 주소가 아니다.
    return &sum; // dangling pointer를 반환하게 된다.
}

int main() {
    int a = 1;
    int b = 2;
    int* res;

    res = ret_dangling_ptr(a, b);

    printf("%d\n", *res);
    return 0;
}
