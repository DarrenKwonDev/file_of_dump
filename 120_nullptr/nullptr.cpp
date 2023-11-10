#include <iostream>

using namespace std;

void getInt(int num) {
    cout << num << endl;
};

int main(void) {
    // int에 NULL을 대입하면 캐스팅되어 문제 발생하는 케이스
    getInt(NULL);    // implicit conversion of NULL -> 0
    getInt(nullptr); // error

    // before nullptr
    int num = NULL; // num is 0
    int* a = NULL;  // null ptr

    // after nullptr
    int num2 = nullptr; // error
    int* a2 = nullptr;  // null ptr.

    return 0;
}
