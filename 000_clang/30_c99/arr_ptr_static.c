#include <assert.h>
#include <stdio.h>

/*
    매개변수_이름[static 한정자 표현식]
    한정자 = const, restrict, etc...
*/

int sum(int nums[static 8], size_t count) {
    // 최소 8개 이상의 원소가 존재함을 hinting
    assert(count >= 8);
}

// dest는 int* const임. 즉, 주소를 보호하는 ptr
// const int* 는 값을 보호하는 포인터.
void copy_nums(int dest[const], const int src[]) {
    dest++; // error
}

int main() {

    return 0;
}