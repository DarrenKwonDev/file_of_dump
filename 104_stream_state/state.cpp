
#include <iostream>

using namespace std;

/*
    https://en.cppreference.com/w/cpp/io/ios_base/iostate

    basic_ios accessors
*/
int main(void) {
    cout << cin.goodbit;
    cout << cin.good();
    cout << " | ";
    cout << cin.eofbit;
    cout << cin.eof();
    cout << " | ";
    cout << cin.failbit;
    cout << cin.fail();
    cout << " | ";
    cout << cin.badbit; // 심각한 오류.. 보통 잘 안 보임. 파일 권한 없다던가.
    cout << cin.bad();

    return 0;
}