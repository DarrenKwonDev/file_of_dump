#include <stdarg.h>
#include <stdio.h>

/*
    아래와 같은 꼴로 작성해서 실수를 줄이자.
    va_start
    {}
    va_end
*/

// 가변 인자 (...) 앞에 자료형이 특정된 매개변수가 반드시 있어야 함.
// 왜?
// 1. 실제 가변 인자에 몇 개나 들어 왔는지 알 수 없다.
// 2. 가변 인자의 자료형도 알 수 없다.
int add_ints(const size_t count, ...) {
    va_list ap; // 가변인자 목록
    size_t i;
    int sum = 0;

    // va_list 초기화
    // va_start(va_list, 가변인자 직전 매개변수)
    // 가변 인자가 stack mem의 어디에서 시작하는 지 알아야 하기 때문에 작성.
    va_start(ap, count);
    { // 중괄호는 필수가 아니나 가독성을 위해.
        for (i = 0; i < count; i++) {
            // 가변 인자를 하나씩 가져옴.
            // 역사적인 문제로 정수는 int 실수는 double임
            sum += va_arg(ap, int);
        }
    }
    // 가변 인자 목록 clean up
    // va_end(가변인자 목록)
    va_end(ap);

    return sum;
}

int main(void) {
    int sum = add_ints(5, 1, 2, 3, 4, 5);
    printf("%d\n", sum); // prints "15
    return 0;
}
