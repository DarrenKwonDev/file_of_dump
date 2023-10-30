#include <bits/stdc++.h>

using namespace std;

class Vec {
private: // default access modifier
    int mX;
    int mY;
};

int main(void) {
    Vec* a = new Vec;           // heap
    Vec* vec_arr = new Vec[10]; // heap 10 Vec.

    delete a; // 객체 메모리 해제
    a = NULL; // optional

    delete[] vec_arr; // 객체 배열 메모리 해제 시 delete[]
    vec_arr = NULL;   // optional

    return 0;
}