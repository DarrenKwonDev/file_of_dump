#include <iostream>
#include <list>

using namespace std;

template <typename T>
class MyArray {
public:
    bool Add(T data) {
        return false;
    };

    MyArray() : mSize(0){};

private:
    enum { MAX = 3 };
    int mSize;
    T mArray[MAX];
};

int main() {
    // template class는 template function과 달리 형을 반드시 적어야 함.
    MyArray<int> temp;

    return 0;
}