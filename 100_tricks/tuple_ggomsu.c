#include <stdio.h>

// int, char[], int
#define TUPLE_DATA       \
    PERSON(0, "Kim", 20) \
    PERSON(1, "Lee", 25) \
    PERSON(2, "Park", 30)

/*
    아래 과정을 하나씩 풀어보자.

    1.
    #define PERSON(id, name, age) id는
    PERSON이란 매크로 함수가 (id, name, age)란 인자를 받아 id만을 반환하는 것을 정의합니다.

    2.
    TUPLE_DATA는 코드 상단에 정의한 매크로 변수를 단순히 풀어냅니다.
    PERSON(0, "Kim", 20)
    PERSON(1, "Lee", 25)
    PERSON(2, "Park", 30)

    3.
    풀어낸 매크로 중 PERSON은 1. 에 정의된 것처럼 id를 반환하는 함수이므로 id만을 반환하게 됩니다.

    4.
    {0, 1, 2}를 풀어낸 후 임시로 정의한 PERSON 매크로 함수는 삭제합니다.
*/

int main() {
    int ids[] = {
#define PERSON(id, name, age) id,
        TUPLE_DATA
#undef PERSON
    };

    const char* names[] = {
#define PERSON(id, name, age) name,
        TUPLE_DATA
#undef PERSON
    };

    int ages[] = {
#define PERSON(id, name, age) age,
        TUPLE_DATA
#undef PERSON
    };

    for (size_t i = 0; i < 3; i++) {
        printf("%d\n", ids[i]);
        printf("%s\n", names[i]);
        printf("%d\n", ages[i]);
    }

    return 0;
}
