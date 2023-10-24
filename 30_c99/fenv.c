
#include <fenv.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

/*
    https://en.cppreference.com/w/c/numeric/fenv/FE_exceptions
    여러 부동 소수점 에러들
    및
    fetestexcept (fe/test/except)
    feraiseexcept (fe/raise/except)
    fegetround() (fe/getround)
    fegetenv()
    등 접두사가 fe인 함수들...
*/
#pragma STDC FENV_ACCESS ON // 해당 pragma를 지정해야만 부동소수점 오류 처리 및 fenv.h

void show_fe_exceptions(void) {
    printf("exceptions raised:");
    if (fetestexcept(FE_DIVBYZERO))
        printf(" FE_DIVBYZERO");
    if (fetestexcept(FE_INEXACT))
        printf(" FE_INEXACT");
    if (fetestexcept(FE_INVALID))
        printf(" FE_INVALID");
    if (fetestexcept(FE_OVERFLOW))
        printf(" FE_OVERFLOW");
    if (fetestexcept(FE_UNDERFLOW))
        printf(" FE_UNDERFLOW");
    feclearexcept(FE_ALL_EXCEPT);
    printf("\n");
}

/*
    https://en.cppreference.com/w/c/numeric/math/math_errhandling
*/
int main() {

    printf("%d\n", MATH_ERRNO);     // 1
    printf("%d\n", MATH_ERREXCEPT); // 2

    printf("%d\n", MATH_ERRNO | MATH_ERREXCEPT);

    // 현재 오류 처리 유형
    // 1(MATH_ERRNO) = errno를 사용
    // 2(MATH_ERREXCEPT) = 부동소수점 예외를 사용
    // 그 외 = 둘 다 사용
    printf("current math err handler: %d\n", math_errhandling);

    // true or false
    printf("IEC 60559(IEEE 부동소수점 연산) 지원?: %d\n", math_errhandling & MATH_ERREXCEPT);

    // 현재 처리 방식이 MATH_ERREXCEPT를 지원하는가?
    printf("MATH_ERREXCEPT is %s\n", math_errhandling & MATH_ERREXCEPT ? "set" : "not set");

    // 에러 예시들
    printf("------------------");

    printf("0.0/0.0 = %f\n", 0.0 / 0.0);
    show_fe_exceptions();

    printf("1.0/0.0 = %f\n", 1.0 / 0.0);
    show_fe_exceptions();

    printf("1.0/10.0 = %f\n", 1.0 / 10.0);
    show_fe_exceptions();

    printf("sqrt(-1) = %f\n", sqrt(-1));
    show_fe_exceptions();

    printf("DBL_MAX*2.0 = %f\n", DBL_MAX * 2.0);
    show_fe_exceptions();

    printf("nextafter(DBL_MIN/pow(2.0,52),0.0) = %.1f\n",
           nextafter(DBL_MIN / pow(2.0, 52), 0.0));
    show_fe_exceptions();

    return 0;
}