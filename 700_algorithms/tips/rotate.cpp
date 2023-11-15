#include <bits/stdc++.h>

using namespace std;

int main(void) {
    vector<int> v = {1, 2, 3, 4, 5};

    // 2칸 왼쪽으로 rotate
    rotate(v.begin(), v.begin() + 2, v.end());
    for (auto k : v) {
        cout << k << " ";
    }
    cout << "\n";

    // 2칸 오른쪽 rotate
    rotate(v.rbegin(), v.rbegin() + 2, v.rend());
    for (auto k : v) {
        cout << k << " ";
    }
}