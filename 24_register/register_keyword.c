#include <stdio.h>

/*
    선언법
    register 자료형 변수명

    1. 전역 변수로 사용 불가. block scope 내에서만 사용 가능.
    2. register 변수는 메모리 주소 없음.

    대부분 컴파일러에서 register 키워드를 무시함.
*/

// error!
// error: illegal storage class on file-scoped variable
register float pi = 3.14f;

int main(void) {
    register int i; // 가능하면 register에 저장.
    register int arr[15];

    // error!
    // error: address of register variable requested
    int* p = &i; // register 변수가 되는 순간 메모리 주소는 존재할 수 없기에.
    int* p_arr = arr;

    return 0;
}