// cin.clear(); // 에러 플래그를 초기화함.
// cin.ignore();         // discard one char
// cin.ignore(10);       // discard 10 char
// cin.ignore(10, '\n'); // discard 10 char but stop when \n
// cin.ignore(LLONG_MAX, '\n');

#include <iostream>

int main(void) {
    int a;
    cin >> a;

    if (cin.fail()) {
        cout << "invalid input\n";
        cin.clear();                 // 에러 플래그 초기화
        cin.ignore(LLONG_MAX, '\n'); // \n이 나올 때 까지 무시하기 (완벽한 방법은 아님에 주의. \n외에 공백 \t 다른 돌변 요소가 아주 많음.)

        // retry
        cin >> a;
        cout << a;
    }

    return 0;
}
