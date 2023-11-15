#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    memcmp를 통한 구조체 비교.

    단점.
    주소를 가진 구조체라면 값이 같아도 주소가 달라 의도대로 비교가 되지 않을 수도 있다.
    (memcmp_struct_ptr 참고)
    그래서 사용하지 않을 것을 권고한다.
*/

typedef struct {
    char name[32];
    int age;
} person_t;

int main(void) {
    person_t p1 = {"John", 20};
    person_t p2 = {"John", 20};
    person_t p3 = {"Aohn", 20};

    // 같으니 0
    int res = memcmp(&p1, &p2, sizeof(person_t));
    printf("res: %d\n", res);

    // 9 (J > A 이므로 왼쪽이 크다. 양수 반환.)
    res = memcmp(&p1, &p3, sizeof(person_t));
    printf("res: %d\n", res);

    // -9 (A < J 이므로 왼쪽이 작다. 음수 반환)
    res = memcmp(&p3, &p1, sizeof(person_t));
    printf("res: %d\n", res);
}