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
    // 정확히는 Vec* 즉, 포인터 변수 b는 stack에 존재하지만
    // 실제 데이터(int 2개인 mX, mY 각 4byte)는 heap에 존재함.
    Vec* b = new Vec();

    // heap 할당된 메모리를 해제하기.
    // stack은 scope 벗어나면 자동 소멸하므로 delete할 수도 없고 필요도 없음.
    delete b;

    return 0;
}