#include <stdio.h>

/*
    union

    똑같은 메모리 위치를 다른 변수로 접근.
    공용체 안에 존재하는 변수들은 같은 메모리를 공유함.
*/

typedef union {
    unsigned char val; // 1byte
    struct {
        unsigned char bit0 : 1;
        unsigned char bit1 : 1;
        unsigned char bit2 : 1;
        unsigned char bit3 : 1;
        unsigned char bit4 : 1;
        unsigned char bit5 : 1;
        unsigned char bit6 : 1;
        unsigned char bit7 : 1;
    } bits; // 1byte
} bitflags_t;

int main() {
    int is_zero;
    bitflags_t flags;

    printf("%lu\n", sizeof(bitflags_t)); // 1 + 1 = 2. 메모리 공간을 공유 하고 있으므로 1 + 1이 아님.

    // bit를 변경해도 val에 영향을 미침.
    flags.bits.bit0 = 1;
    flags.bits.bit1 = 0;

    is_zero = flags.val == 0;
    printf("is_zero: %d\n", is_zero); // 0

    return 0;
}
