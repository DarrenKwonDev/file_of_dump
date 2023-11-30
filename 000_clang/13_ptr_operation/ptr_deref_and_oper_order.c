#include <stdio.h>

/*
    heuristic

    전위 연산은 오른쪽으로 평가함
    *++p는 ++먼저하고 *
    ++*p는 *먼저하고 ++

    후위 연산이 존재할 경우 앞서 모든 작업을 처리한 후 후위 연산 적용
    괄호가 있으면 괄호 먼저.
*/

int main(void) {
    int nums[] = {134, 68, 47956};
    int* p = nums; /* 변수 nums의 주소가 0x104라 가정 */
    printf("%d, %p\n", *p, p);

    // 역참조 먼저 + 후위 연산 나중에
    int num = *p++; // num: 134, p: 0x108
    printf("%d, %p\n", num, p);

    // 역참조 먼저 + 후위 연산 나중에
    // 후위 연산이므로 num엔 134가 반영됨.
    int num = (*p)++; // num: 134, p: 0x104
    printf("%d, %p\n", num, p);

    // // 전위 연산 먼저 + 역참조 나중에
    int num = *++p; // num: 68, p: 0x108
    printf("%d, %p\n", num, p);

    // // 역참조 먼저 + 전위 연산 (as a int)
    int num = ++*p; // num: 135, p: 0x104
    printf("%d, %p\n", num, p);

    return 0;
}

// quiz
{
    int arr[7] = {3, 5, 7, 9, 11, 13, 15}; /* arr의 주소는 0x100 */
    int* ptr = arr + 2;                    /* ptr의 주소는 0x108 */
    const int NUM = *ptr++;                // deref를 먼저하고 ptr을 증가시킴.

    printf("%d\n", NUM);      /* 7 */
    printf("%p", (void*)ptr); /* 0x10c */

    return 0;
}

{
    int arr[7] = {3, 5, 7, 9, 11, 13, 15}; /* arr의 주소는 0x100 */
    int* ptr = arr + 5;                    // 13을 가리킴. ptr = 0x114
    const int NUM = *++ptr;                // ptr을 먼저 증가시키고 deref.

    printf("%d\n", NUM);      /* 15 */
    printf("%p", (void*)ptr); /* 0x118 */

    return 0;
}
