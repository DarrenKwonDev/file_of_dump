
#include <stdio.h>

/*
    왜 이런 union을 만들었나?
    메모리 공간을 공유하지만 부분과 전체의 관계도 아니고 오히려 문제를 일으킬 여지.

    아래의 경우
    00 00 00 00 00 00 00 00
    8 바이트고 앞의 4바이트를 int와 double이 공유하는 이상한 모양새이다.
*/
typedef union {
    int ivalue;
    double dvalue;
} value_t;

typedef union {
    int ivalue;
    float fvalue;
    double dvalue;
    char cvalue;
    short svalue;
} value2_t;

int main() {
    value_t op1;

    printf("%lu\n", sizeof(value_t));  // 8. 메모리 공간을 공유 하고 있으므로 4 + 8이 아님.
    printf("%lu\n", sizeof(value2_t)); // 8

    return 0;
}
