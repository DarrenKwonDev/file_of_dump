#include <stdio.h>

// null ptr의 역참조는 하지 말아라. 애초에 없는 메모리 주소를 찾겠다는거 아니냐.
void test_01(void) {
    int* p = NULL;
    printf("%d\n", *p); // null ptr의 역참조. 표준에 정의되지 않음
    // 나는 segmentation fault 받음
}

int main(void) {
    test_01();
    return 0;
}