#include <stdio.h>

int main(void) {
    int nums1[5] = {1, 2}; // 에러 안 남. 나머지가 0으로 초기화
    int nums2[5] = {
        0, // 쉼표를 꼭 찍어야 모든 원소가 0으로 초기화
    };

    size_t i = 0;

    for (i = 0; i < 5; i++) {
        printf("%d\n", nums1[i]);
    }

    for (i = 0; i < 5; i++) {
        printf("%d\n", nums2[i]);
    }

    return 0;
}