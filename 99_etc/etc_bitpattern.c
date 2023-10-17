#include <stdio.h>

typedef union {
    unsigned char val; // 1byte (8bit)
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

/*
    2진수 서식지정자가 없다...
*/
int main(void) {
    int num;
    scanf("%d", &num);

    bitflags_t flags;
    flags.val = num;

    printf("%u%u%u%u%u%u%u%u\n", flags.bits.bit7, flags.bits.bit6, flags.bits.bit5, flags.bits.bit4, flags.bits.bit3, flags.bits.bit2, flags.bits.bit1, flags.bits.bit0);

    return 0;
}