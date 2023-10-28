#include <iostream>

using namespace std;

void insert(int idx, int num, int arr[], int& len) {
    // 1. idx가 len을 넘지 않는지 검사한다. (assert 생략)

    // early exit
    if (idx == len) {
        arr[idx] = num;
        len++;
        return;
    }

    // 2. idx부터 끝까지 뒤로 한 칸 씩 민다.
    // 2가 주어지면, arr[2] 부터 arr[len - 1] 까지를 전부 + 1씩 한다.
    for (int i = len; i >= idx; i--) {
        arr[i + 1] = arr[i];
    }

    // 3. 빈 idx에 값을 넣는다.
    arr[idx] = num;

    // 4. len을 증가시킨다.
    len++;
}

void erase(int idx, int arr[], int& len) {
    // idx가 len 범위 내 인지 확인한다 (assert 생략)

    // early exit
    // 맨 마지막 pop
    if (idx == len) {
        len--;
        return;
    }

    // 1. idx부터 끝까지 앞으로 한 칸씩 당긴다.
    // 1이 주어지면
    // arr[1] = arr[2]
    // arr[2] = arr[3]
    // arr[len - 2] = arr[len - 1]
    for (int i = idx; i < len - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // 2. len을 줄인다
    len--;
}

void printArr(int arr[], int& len) {
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << "\n\n";
}

void insert_test() {
    cout << "***** insert_test *****\n";
    int arr[10] = {10, 20, 30};
    int len = 3;
    insert(3, 40, arr, len); // 10 20 30 40
    printArr(arr, len);
    insert(1, 50, arr, len); // 10 50 20 30 40
    printArr(arr, len);
    insert(0, 15, arr, len); // 15 10 50 20 30 40
    printArr(arr, len);
}

void erase_test() {
    cout << "***** erase_test *****\n";
    int arr[10] = {10, 50, 40, 30, 70, 20};
    int len = 6;
    erase(4, arr, len); // 10 50 40 30 20
    printArr(arr, len);
    erase(1, arr, len); // 10 40 30 20
    printArr(arr, len);
    erase(3, arr, len); // 10 40 30
    printArr(arr, len);
}

int main(void) {
    insert_test();
    erase_test();
}