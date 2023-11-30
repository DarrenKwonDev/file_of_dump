#include <iostream>
#include <vector>

using namespace std;

/*
    begin, end
    rbegin, rend (reverse begin, reverse end)
*/
int main(void) {
    vector<int> v;
    vector<int>::reverse_iterator ri;

    v.reserve(10);

    v.push_back(1);
    v.push_back(3);
    v.push_back(9);
    v.push_back(7);

    // 특이하게도, begin이 순서상 앞에 있음에도 ++로 연산해야 함.
    for (ri = v.rbegin(); ri != v.rend(); ri++) {
        cout << *ri << endl;
    }

    return 0;
}
