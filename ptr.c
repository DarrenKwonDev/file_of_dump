#include <stdio.h>

void print_all_mat(int matrix[][3], size_t rowCount) {
    size_t i, j;
    for (i = 0; i < rowCount; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6},
    };

    int(*ptr)[3] = arr; // 열이 3인 2차원 배열 포인터

    // 2차원 배열을 가리키는 포인터는 첫 행 배열의 주소를 가리킨다.
    // 따라서 (0, 0) 원소를 출력하기 위해서는 두 번 deref해야 한다.
    printf("ptr is... %p, %p, %d\n", ptr, *ptr, **ptr);

    // 배열 행의 시작 주소를 출력해보자.
    // arr[0] == ptr[0] 이다.
    printf("is arr[0] and ptr[0] same? : %d\n", arr[0] == ptr[0]);

    printf("%p, %p\n", arr[0], ptr[0]);
    printf("%p, %p\n", arr[1], ptr[1]);
    printf("%p, %p\n", arr[2], ptr[2]);

    // 특정 원소를 출력해보자.
    // 각각 (0행 1열), (1행 2열)의 값을 출력하라는 의미.
    printf("%d, %d\n", arr[0][1], arr[1][2]);
    printf("%d, %d\n", ptr[0][1], *(ptr[1] + 2));

    printf("size of matrix : %lu\n", sizeof(arr)); // 4(int) * 2 * 3 = 24
    printf("size of ptr : %lu\n", sizeof(ptr));    // x64기준 8byte. 포인터 크기는 무조건 word size

    // 2차원 배열을 매개 변수로 전달한다면
    print_all_mat(arr, 2);

    return 0;
}
