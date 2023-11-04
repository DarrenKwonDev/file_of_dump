#include <iostream>
#include <vector>

using namespace std;

/*
    https://en.cppreference.com/w/cpp/container/vector/insert
    https://en.cppreference.com/w/cpp/container/vector/erase
*/

int main(void) {
    vector<int> v;
    v.reserve(10);
    vector<int>::iterator i;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    // 1 2 3 4
    // ^
    // begin()
    // 즉, [2] 자리에 99를 삽입
    // 1 2 99 3 4
    i = v.insert(v.begin() + 2, 99);
    cout << *i << endl; // 99가 삽입된 위치를 가리키는 반복자가 반환됨.

    // https : // en.cppreference.com/w/cpp/container/vector/erase
    // 첫번째 원소를 지우고, 다음 원소를 가리키는 포인터를 반환함.
    // 1을 지웠고, 원소가 당겼으니 2를 가리키는 반복자 반환됨.
    i = v.erase(v.begin());
    cout << *i << endl; // should be 2. (2 99 3 4)

    // FIXME: DON NOT THIS
    // the end() iterator (which is valid, but is not dereferenceable) cannot be used as a value for pos.
    // https://en.cppreference.com/w/cpp/container/vector/erase
    // v.erase(v.end())

    // 그러나, 마지막 원소를 지웠다?
    // 그렇다면 v.end()가 반환됨. 즉, 마지막 원소를 가리키는 원소를 가리키지 않는다는 것임.
    // If pos refers to the last element, then the end() iterator is returned.
    i = v.erase(v.end() - 1); // 마지막 원소인 4를 지움.
    cout << *(--i) << endl;   // should be 3 (v.end()를 반환함.)

    // for (auto k : v) {
    //     cout << k << endl;
    // }

    return 0;
}
