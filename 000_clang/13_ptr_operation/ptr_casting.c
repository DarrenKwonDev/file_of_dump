#include <stdio.h>

/*
    ptr casting
    배열 포인터에 접근할 때 단위를 조작하는 것.
*/

int main(void) {
    // 일반 casting
    int a = 3;
    printf("%f\n", (float)a); // 3.000000

    // ptr casting
    int nums[3] = {1, 2, 3};
    int* ptr1 = &nums[1];

    // casting 자료형의 단위로 메모리 이동할 수 있게 됨.
    // 즉, ptr casting은 접근할 때의 단위를 조작하는 것.
    printf("%p, %p\n", ptr1, (char*)ptr1 + 1);  // 1b 이동
    printf("%p, %p\n", ptr1, (short*)ptr1 + 1); // 2b 이동

    // 다만 의도한 숫자를 얻을 목적이라면 casting을 하지 않는 것이 좋다.
    printf("intend 3 but got %d\n", (char*)ptr1 + 1);

    return 0;
}