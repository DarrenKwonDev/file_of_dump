#include <stdio.h>

/*
    C에서는 exception이 없음.
    버그 : 일어날 수 없다고 가정한 것. 프로그램에서 대응할 수 없음. 다시 만들어야 함.
    오류 : 실제 실행 중 일어날 수 있는 예외적 상황. 프로그램에서 대처해야 함.
*/
void swap(int* a, int* b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void) {
    int* a = NULL;
    printf("%d", *a);
    return 0;
}