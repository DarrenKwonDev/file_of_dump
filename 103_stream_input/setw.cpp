#include <iomanip>
#include <iostream>

using namespace std;

int main(void) {
    char str[4];

    // 만약 4자 이상 문자열이 들어오면 \0를 넣어주지 않음. 문제 생길 여지 있음.
    // scanf("%s", str)과 동일한 문제가 발생함.
    // cin >> str;
    // str[3] = '\0'; // 그래서 C에서는 안전한 처리를 위해 마지막에 방어적으로 \0를 넣어주었다.

    // 버퍼 사이즈에 맞게 setw로 잘라주면 c++에서는 좀 더 간략하게 안전하게 가져올 수 있다.
    // https://en.cppreference.com/w/cpp/io/manip/setw
    cin >>
        setw(4) >> str;

    cout << str;
    return 0;
}