#include <stdio.h>

int main(void) {
    int i = 0;
    int j = 0;
    int k = 0;

    // short circuit evaluation
    // ++i 이 1이므로 || 뒤는 eval되지 않고 넘어가게 됨.
    if (++i || ++j && ++k) {
        printf("true\n");
    }

    printf("%d, %d, %d\n", i, j, k); // 1, 0, 0

    return 0;
}