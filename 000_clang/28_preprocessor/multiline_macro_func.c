#include <stdio.h>

// 여러 줄 매크로 함수.
// C 언어에서 백슬래시와 개행 문자 사이에 공백이 있으면 에러를 발생시킬 수 있으니 주의.
#define ADD(x, y, z)                 \
    for (size_t i = 0; i < 3; i++) { \
        x = x + y + z;               \
    }

// __asm { int 3 }는 x86 어셈블리에서 프로그램을 중지할 때 사용하는 interrupt.
#define X86_ASSERT(condition, msg)                               \
    if (!(condition)) {                                          \
        fprintf(stderr, "%s(%s:%d)\n", msg, __FILE__, __LINE__); \
        __asm { int 3 }                                           \
        ;                                                        \
    }

int main() {
    int a, b, c;
    a = 10;
    b = 20;
    c = 30;

    ADD(a, b, c);

    return 0;
}
