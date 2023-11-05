#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    vector<int> v;
    v.reserve(4); // cap 4로 설정.

    v.push_back(30);
    v.push_back(245);
    v.push_back(3);
    v.push_back(79);

    // 초과분은 제거.
    // 현재 cap보다 더 커지면 재할당이 일어남.
    v.resize(2);

    // 30 245
    for (vector<int>::iterator i = v.begin(); i < v.end(); i++) {
        cout << *i << endl;
    }

    // cap은 유지한채 원소 전부 제거
    v.clear();

    return 0;
}
