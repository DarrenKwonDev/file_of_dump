#include "vector.h"
#include <bits/stdc++.h>

using namespace std;

class String {
public:
    String() : mLength(0),
               mCapacity(15) {
        // 동적 할당된 문자 배열
        mChars = new char[mCapacity + 1];
    };
    ~String() {
        // 소멸자를 통해 동적 할당된 배열로 메모리 해제.
        delete[] mChars;
    };

private:
    char* mChars;
    int mLength;
    int mCapacity;
};

int main(void) {
    String stack_str = String();
    String* str = new String();

    delete str;

    return 0;
}