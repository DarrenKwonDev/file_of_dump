#include <stdio.h>

/*
    반환형 (*변수명)(매개변수 목록)
*/

int add(int a, int b) {
    return a + b;
}

void print(int a) {
    printf("%d\n", a);
}

int calc(int (*fp)(int, int), int a, int b) {
    return fp(a, b);
}

int main(void) {
    int (*fp)(int, int) = &add;
    void (*fp2)(int) = &print;
    int (*func[2])(float, float); // 함수 포인터 원소 2개 배열

    printf("%d\n", calc(fp, 10, 20)); // 30

    return 0;
}