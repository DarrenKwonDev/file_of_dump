#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int arr[3] = {1, 2, 3};
    int ret[3];

    memcpy(ret, arr, sizeof(ret));

    for (size_t i = 0; i < 3; i++) {
        cout << ret[i] << " ";
    }

    vector<int> v1 = {1, 2, 3};
    vector<int> v2(3);

    copy(v1.begin(), v1.end(), v2.begin());
    for (auto k : v2) {
        cout << k << " ";
    }
}