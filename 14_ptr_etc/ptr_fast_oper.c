#include <stdio.h>

int sum(int* start, int* end) {
    int tot = 0;
    int* p = start;

    while (p <= end) {
        tot += *p++;
    }

    return tot;
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5};

    int res = sum(arr, arr + 4);

    printf("%d\n", res);

    return 0;
}