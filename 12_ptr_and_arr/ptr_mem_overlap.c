#include <stdio.h>

#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

int isOverlap(
    int arr1[],
    const size_t len1,
    int arr2[],
    const size_t len2) {

    // arr1이 메모리상 arr2보다 왼쪽에 있다면
    // arr1의 마지막 원소 주소가 arr의 첫번째 원소 주소보다 크면 겹친다.
    // arr1이 메모리상 arr2보다 오른쪽에 있다면 반대로 비교한다.
    return arr1 <= arr2 ? arr1 + len1 > arr2 : arr2 + len2 > arr1;
}

int main(void) {
    int num1[5] = {1, 2, 3, 4, 5};
    int num2[3] = {1, 2, 3};
    int* num3 = num1 + 2; // num1의 3번째 원소 주소

    // num1과 num2는 겹치지 않는다. 따로 선언 되었기에.
    printf("%d\n", isOverlap(num1, ARRAY_LENGTH(num1), num2, ARRAY_LENGTH(num2))); // 0

    // num3는 num1의 3번재 원소를 포인터로 가리키고 있으므로 겹친다.
    printf("%d\n", isOverlap(num1, ARRAY_LENGTH(num1), num3, 1)); // 1

    return 0;
}