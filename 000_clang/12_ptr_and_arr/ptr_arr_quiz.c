

int main(void) {
    int arr[5] = {5, 10, 15, 20, 25};
    int* ptr = arr + 2; // 15 가리키는 포인터

    arr = ptr + 1; // arr에 ptr를 할당할 수 없으므로 에러 발생함.

    printf("%d %d", *arr, *ptr);

    return 0;
}
