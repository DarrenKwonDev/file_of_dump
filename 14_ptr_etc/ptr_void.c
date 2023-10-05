#include <stdio.h>

typedef struct {
    int x;
    int y;
} point_t;

int main(void) {
    void* p;
    int a = 3;
    float b = 3.1f;
    point_t pt = {1, 2};

    // everything is ok
    p = &a;
    p = &b;
    p = &pt;

    return 0;
}
