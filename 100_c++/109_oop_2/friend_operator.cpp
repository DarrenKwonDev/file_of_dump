#include <bits/stdc++.h>
using namespace std;

class X {
    // x의 private, protected에 접근 가능한 friend들.
    friend class Y;                                        // Y에서
    friend void Foo(X&);                                   // 전역 함수인 Foo 함수에서
    friend ostream& operator<<(ostream& os, const X& rhs); // 전역 함수인 operator << 에서

private:
    int mPrivate = 3;
};

class Y {
public:
    void PrintXMember(X& x) {
        cout << x.mPrivate << endl;
    }
};

void Foo(X& x) {
    cout << x.mPrivate << endl;
}

// operator<<는
ostream& operator<<(ostream& os, const X& rhs) {
    os << "overloaded  " << rhs.mPrivate;
    // << 연산은 chaining 되는 경우가 잦으므로 os를 반환해주어야 함.
    // << chaining example -> cout << "asdf" << ", " << endl;
    return os;
}

int main(void) {
    Y y;
    X x;

    y.PrintXMember(x);
    Foo(x);

    cout << x << endl;

    return 0;
}