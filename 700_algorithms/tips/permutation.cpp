#include <bits/stdc++.h>

using namespace std;

int main(void) {
    vector<int> v = {1, 2, 3, 4};

    // permutation
    do {
        for (auto k : v) {
            cout << k << " ";
        }
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));

    reverse(v.begin(), v.end());

    cout << "---" << endl;

    do {
        for (auto k : v) {
            cout << k << " ";
        }
        cout << endl;
    } while (prev_permutation(v.begin(), v.end()));
}