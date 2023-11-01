#include <bits/stdc++.h>
using namespace std;

class Twitter {
public:
    Twitter(){};

    void twit(int num) {
        cout << "number " << num << endl;
    };

    // compile error. 이름이 같은데 반환형이 다름.
    // int twit(int num){};
    // functions that differ only in their return type cannot be overloaded

    void twit(char* str, int len) {
        char* p = str;
        int cnt = 0;
        while (cnt != len) {
            cout << *p;
            cnt++;
            p++;
        }
    };
    void twit(float f, string str) {
        cout << ceil(f) << " " << str << endl;
    };
};

int main(void) {
    Twitter t;
    string str = "abcd";
    char str2[] = "java";

    t.twit(3);
    t.twit(3.14, str);
    t.twit(str2, 4);

    return 0;
}