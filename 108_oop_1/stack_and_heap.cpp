#include <bits/stdc++.h>

using namespace std;

class Vec {
private: // default access modifier
    int mX;
    int mY;
};

void printVec(const Vec& a, const Vec& b) {
    Vec* v = new Vec(); // heap 할당

    /* do something */

    delete v; // why? heap 할당된 데이터 삭제.
}

int main(void) {
    // stack에 할당. (빠름)
    Vec a;

    // heap에 할당. (느림)
    Vec* b = new Vec();

    // heap 할당된 메모리를 해제하기.
    // stack은 scope 벗어나면 자동 소멸하므로 delete할 수도 없고 필요도 없음.
    delete b;

    return 0;
}