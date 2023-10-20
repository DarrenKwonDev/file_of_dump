#include <stdio.h>

#ifndef A
#define A 10
#endif

#if !defined(B) // same as #ifndef B
#define B 20
#endif

#if defined(C)
#undef C
#endif

int main() {

    return 0;
}
