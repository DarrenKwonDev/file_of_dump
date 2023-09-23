#include <stdio.h>

void print_ptr(void) {
    int num = 10;
    int* p_num = &num;      // num의 주소
    int** p_p_num = &p_num; // p_num의 주소

    // %p: pointer. hex로 출력
    printf("%p\n", &num);
    printf("%p\n", (void*)&num);

    // dereference
    printf("%d\n", *p_num);
}

// pointer를 인자로 받는 함수
void mutate_arguments(float* ptr) {
    *ptr = 2.718; // 역참조를 통해서 값 변경.
    printf("%f\n", *ptr);
}

int main(void) {
    float test_num = 3.14;

    print_ptr();

    mutate_arguments(&test_num);
    printf("%f\n", test_num); // 2.718

    return 0;
}
