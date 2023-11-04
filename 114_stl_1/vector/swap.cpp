#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> v;
    v.reserve(2);
    v.push_back(20);
    v.push_back(43);

    vector<int> v2;
    v2.assign(7, 290);

    // https://en.cppreference.com/w/cpp/container/vector/swap
    // v1과 v2간의 swap
    // 재할당이 일어나지 않음. 생각해보면 v, v2의 주소값만 바꿔주면 되는 일임!

    // 공식 문서에도 그렇게 설명함.
    // Does not invoke any move, copy, or swap operations on individual elements.
    v.swap(v2);

    return 0;
}
