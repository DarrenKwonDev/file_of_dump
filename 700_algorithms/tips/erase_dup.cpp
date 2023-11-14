#include <bits/stdc++.h>

using namespace std;

int main(void) {

    vector<int> v = {1, 1, 1, 7, 2, 4, 2, 2};

    // 중복을 실제로 삭제하는 것이 아니라 중복 요소를 범위의 뒷 부분으로 옮기고
    // 중복이 제거된 범위의 끝을 반환합니다.

    // 의도한대로 중복을 뒤로 미려면 일단 소팅해야.
    sort(v.begin(), v.end());

    auto endIt = unique(v.begin(), v.end());
    for (auto it = v.begin(); it != endIt; ++it) {
        cout << *it << " ";
    }

    cout << endl;

    // 본래 배열을 중복 삭제하고 싶다.
    v.erase(endIt, v.end());
    for (auto k : v) {
        cout << k << " ";
    }
}