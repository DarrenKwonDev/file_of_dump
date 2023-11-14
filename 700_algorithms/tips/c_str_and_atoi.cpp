#include <bits/stdc++.h>

using namespace std;

int main(void) {

    string s = "123s5";
    const char* p = s.c_str();

    while (*p != '\0') {
        cout << *p << endl;
        p++;
    }

    // 가능한 곳까지 숫자로 반환해줌.
    cout << atoi(s.c_str()) << endl;

    return 0;
}