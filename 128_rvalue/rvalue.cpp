#include <iostream>
#include <vector>

using namespace std;

vector<int> addAllOne(const vector<int> v) {
    vector<int> o;
    o.reserve(v.size());

    for (auto value : v) {
        o.push_back(value + 1);
    }

    // 함수의 반환값을 복사되어 나간다.
    // scope 내의 지역 변수들은 함수를 벗어나면서 사라지거나 방치된다.
    // 따라서 함수의 반환값은 rvalue이다.
    return o;
}

int main() {

    // rvalue example 1. 함수의 반환값.
    vector<int> v = {1, 2};
    // addAllOne 함수의 반환값을 복사 받는다.
    vector<int> output = addAllOne(v);

    // rvalue example 2. 대입(복사)
    // num은 left value, 10은 right value.
    int num = 10; // 10이란 rvalue를 num에 복사

    return 0;
}
