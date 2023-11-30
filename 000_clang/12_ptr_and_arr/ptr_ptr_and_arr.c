#include <stdio.h>

/*
    1.
    pointer에 값을 넣을 땐 주소 연산자 &를 ptr에 대입하였다.
    그러나 배열은 포인터에 직접 대입할 수 있고, 해당 포인터는 배열의 첫 원소 주소를 반환한다.

    2.
    arr를 가리키는 ptr에 정수를 더하거나 빼는 것은 (++, -- 도 포함) 다음 원소 주소로의 이동을 의미한다.
*/
int main(void) {
    float nums[6] = {1, 2, 3, 4, 5, 6};
    float* ptr1 = NULL;

    // 아래 두 코드는 같은 의미이다.
    ptr1 = nums;     // 배열의 이름은 배열의 첫번째 원소의 주소를 가리킴
    ptr1 = &nums[0]; // 값 형의 경우에는 주소 연산자 필요.

    printf("%p, %f\n", ptr1, *ptr1);

    ptr1++;                          // ptr1이 가리키는 주소를 4byte만큼 증가시킴
    printf("%p, %f\n", ptr1, *ptr1); // array의 다음 원소의 주소를 가리킴

    ptr1 += 2;
    printf("%p, %f\n", ptr1, *ptr1);

    // ptr에서 []로 다음, 이전 원소로 이동 가능하며 자동으로 deref된다.
    // 즉, ptr1[1] 와 *(ptr1 + 1)는 같다.
    printf("%f, %f\n", ptr1[1], *(ptr1 + 1));

    return 0;
}
