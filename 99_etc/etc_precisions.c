#include <float.h>
#include <stdio.h>

int main(void) {
    printf("float의 정밀도: %d\n", FLT_DIG);
    printf("double의 정밀도: %d\n", DBL_DIG);
    printf("long double의 정밀도: %d\n", LDBL_DIG);
}