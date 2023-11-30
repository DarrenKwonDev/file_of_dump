#include <stdio.h>
#include <stdlib.h>

size_t align_up(const size_t alignment, const size_t size) {
    // 올림 연산
    return (size + alignment - 1) / alignment * alignment;
}

int main(void) {
    int* p1 = malloc(64); // 일반 malloc
    printf("%p\n", p1);
    free(p1);
    p1 = NULL;

    // size는 반드시 alignment의 배수여야 함.
    // p2는 4096의 배수임
    int* p2 = aligned_alloc(4096, sizeof(int));
    printf("%p\n", p2);
    free(p2); // aligned_alloc 또한 메모리 해제가 필요
    p2 = NULL;

    const size_t num_bytes = align_up(4096, sizeof(int));
    int* p3 = aligned_alloc(4096, num_bytes);
    printf("%p\n", p3);
    free(p3);
    p3 = NULL;

    return 0;
}