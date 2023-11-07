#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int age;
} person_t;

int main(void) {
    person_t p1 = {"John", 20};
    person_t p2;
    size_t size;

    size = strlen(p1.name) + 1; // for null character
    p2.name = malloc(size);

    memcpy(p2.name, p1.name, size);

    p2.age = p1.age; // 값은 기본이 깊은 복사이므로.

    // 값은 같으나 주소는 다름
    printf("%s, %s\n", p1.name, p2.name);
    printf("%p, %p\n", p1.name, p2.name);

    // 기본형들의 주소와 값이 같은 것을 확인 가능
    printf("%d, %d\n", p1.age, p2.age);
    printf("%p, %p\n", &p1.age, &p2.age);

    // 따라서, memcmp를 통해 비교하면 다르다고 나옴.
    // p1.name의 주소 0x102e87f90
    // p2.name의 주소 0x1496066d0
    // 앞에서 부터 비교시 0 < 4 이므로 왼쪽이 작아 음수 반환.
    // 물론 실행할 때마다 메모리 주소값이 달라져 결과도 달라지지만.
    int res = memcmp(&p1, &p2, sizeof(person_t)); // 주소를 가진 구조체라면 값이 같아도 주소가 달라 의도대로 비교가 되지 않을 수도 있다.
    printf("res: %d\n", res);

    free(p2.name);
    p2.name = NULL;
}