#include <stdio.h>

typedef struct {
    unsigned char b0 : 1; // 1 byte 중 1 bit만 사용
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
} bigflags_t;

int main() {
    printf("%zu byte\n", sizeof(bigflags_t)); // 1
    return 0;
}
