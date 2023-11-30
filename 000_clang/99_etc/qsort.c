#include <stdio.h>
#include <stdlib.h>

// int (*comp)(const void *, const void *)

// comparison function which returns ​a negative integer value if the first argument is less than the second,
// a positive integer value if the first argument is greater than the second and zero if the arguments are equivalent.
int cmp(const void* a, const void* b) {
    int left = *(int*)a;
    int right = *(int*)b;

    // 왼쪽(첫인자)이 작으면 음수
    // 왼쪽(첫인자)이 크면 양수
    // 같으면 0
    return left - right; // ascending 가정.
}
int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int arr[3] = {a, b, c};

    // qsort
    // https://en.cppreference.com/w/c/algorithm/qsort
    qsort(arr, 3, sizeof(int), cmp); // 오름차순 정렬

    printf("%d", arr[1]);

    return 0;
}