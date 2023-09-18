#include <stdio.h>

/*
    float은 IEEE 754 Single(32bit)로 표현된다.
    double은 IEEE 754 Double(64bit)로 표현된다.
*/

int main(void) {
    /*
        float
    */
    float f = 3.141592f; // float literal
    double d = 3.141592; // double literal
    printf("%f, %f", f, d);

    return 0;
}