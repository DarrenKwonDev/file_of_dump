#include <stdio.h>

/*
    구조체의 원소에 '포인터'가 들어간다는 것은?
    1. 얕은 복사를 하게 되어 원본이 mutate된다는 것.
    2. 파일 저장 등 어딘가에 저장할 때 데이터를 저장하지 않고 프로그램이 종료하면 의미 없는 메모리 주소만 저장된다는 것.
*/
typedef struct name {
    char* lastname;
    char* firstname;
} name_t;

int main() {
    char firstname[] = "Lulu";
    char lastname[] = "Lee";

    name_t name;
    name_t clone;

    name.lastname = lastname;
    name.firstname = firstname;

    clone = name; // 구조체 얕은 복사 (주소만 복사)

    name.lastname[0] = 'N';

    printf("origin: %s %s\n", name.firstname, name.lastname);
    printf("clone: %s %s\n", clone.firstname, clone.lastname);

    return 0;
}
