#include <iostream>

using namespace std;

int main(void) {
    // string concat
    string a;
    cin >> a;

    a += " oh";
    cout << a + " with concat";

    // c_str
    string s = "wow";
    const char* p_s = s.c_str(); // 문자 배열의 첫 주소 포인터 반환. C style이라서 c_str.
    while (*p_s != '\0') {
        cout << *p_s << "|";
        *p_s++;
    }

    // idx
    string s2 = "abce";
    cout << s2[1];

    // 비교 가능
    string str1, str2;
    str1 = "abcd";
    str2 = "abcc";

    bool rel = str1 > str2; // true
    cout << boolalpha << rel;
    return 0;
}