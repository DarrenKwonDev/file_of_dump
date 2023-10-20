#include <stdio.h>

#define A 10
#undef A // A 식별자를 없앰.

int main() {
    printf("%d\n", A); // error: use of undeclared identifier 'A'
    return 0;
}
