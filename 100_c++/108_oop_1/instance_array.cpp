#include <bits/stdc++.h>

using namespace std;

class Vec {
private: // default access modifier
    int mX;
    int mY;
};

int main(void) {
    // Vec 10개 heap에 초기화
    Vec* list = new Vec[10];

    // Vec ptr 10개 heap에 초기화
    // list_heap is pointer to (pointer to Vec)
    Vec** list_heap = new Vec*[10];

    return 0;
}