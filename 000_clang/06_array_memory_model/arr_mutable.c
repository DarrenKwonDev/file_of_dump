#include <stdio.h>

void process(int nums[3]) {
    // 여기서 넘어오는 nums는 ptr이다. 따라서 여기의 조작은 원본에 영향을 미침
    size_t i;
    for (i = 0; i < 3; i++) {
        nums[i] *= 2;
    }
}

int main(void) {
    int nums[3] = {1, 2, 3}; // original
    size_t i = 0;

    process(nums);

    for (i = 0; i < 3; i++) {
        printf("%d\n", nums[i]);
    }

    return 0;
}