#include <stdio.h>
// little endian을 가정.
// ```python
// >>> import sys
// >>> sys.byteorder
// ```
typedef union {
    unsigned int val; // 4byte

    struct {
        unsigned char r; // 1byte
        unsigned char g;
        unsigned char b;
        unsigned char a;
    } rgba; // 4byte
} color_t;

int main() {
    color_t red;
    color_t yellow;

    printf("%lu\n", sizeof(color_t)); // 4 + 4 = 8. 메모리 공간을 공유 하고 있으므로 4 + 4가 아님.

    red.val = 0; // init all bits to 0
    red.rgba.r = 255;

    yellow = red;
    yellow.rgba.g = 255;

    printf("%#x\n", red.val);
    printf("%#x\n", yellow.val);

    return 0;
}
