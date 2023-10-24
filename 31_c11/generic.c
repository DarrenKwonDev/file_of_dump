#include <math.h>
#include <stdio.h>

/*
    _Generic(<제어 표현식>, <연관 목록>)
    컴파일 도중 (not runtime) 표현식으로 변환됨.
*/
#define ceil(X) _Generic((X), \
    long double: ceill,       \
    default: ceil,            \
    float: ceilf)(X)

int main(void) {
    float f = 3.14f;
    double d = 1245.263;

    printf("%.1f, %.1f", ceil(f), ceil(d));

    return 0;
}