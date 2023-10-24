#include <stdio.h>
#include <stdnoreturn.h>

noreturn void burn_the_bridge() {
    // 호출자인 main으로 돌아가지 않음.
    while (1) {
    }
}; // 여기를 빠져나가는 순간 return된 것임.

int main(void) {
    burn_the_bridge();
    printf("oh..\n"); // 닿지 않음.
    return 0;
}