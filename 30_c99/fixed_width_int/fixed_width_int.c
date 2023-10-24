#include <stdint.h>
#include <stdio.h>

int main() {
    uint32_t a;
    int64_t b;
    int8_t c;

    printf("%lu ", sizeof(a));
    printf("%lu ", sizeof(b));
    printf("%lu ", sizeof(c));

    return 0;
}
