#include <bits/stdc++.h>

using namespace std;

class Vec {
public:
    // initializer list (초기화 리스트)
    // object가 만들어 질 때 값이 초기화.
    Vec() : mX(0), mY(0) {}

    // 대입 방식. (초기화가 아님)
    // object가 만들어 진 후에 대입이 이루어짐.
    // 따라서 const 등이 값의 할당이 불가능하며 제한적임.
    // Vec() {
    //     mX = 0;
    //     mY = 0;
    // }

private:
    int mX;
    int mY;
};

int main(void) {
    Vec* a = new Vec();

    return 0;
}