#include <stdio.h>

int main(void) {
    float num = 0.0f;

    for (size_t i = 0; i < 100; i++) {
        num += 0.1f;
    }

    printf("%f\n", num); // 10.000002
}