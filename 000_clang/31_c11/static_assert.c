#include <assert.h>
#include <stdio.h>

// 컴파일은 된다. assert가 런타임에 돌아서 그렇지
float div(float a, float b) {
    assert(b != 0.0f); // 동적 assert. runtime 중 잡힘
    return a / b;
}

typedef struct {
    int x;
} test_t;

int main(void) {
    float a = 10.4f;
    float b = 0.0f;
    // div(a, b); // 이 함수가 돌아야만 assert를 건드림

    // 컴파일 타임에 검증.
    static_assert(sizeof(test_t) == 4, "struct size should be 4");

    return 0;
}