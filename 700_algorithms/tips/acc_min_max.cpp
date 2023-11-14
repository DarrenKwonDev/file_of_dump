#include <bits/stdc++.h>

using namespace std;

int main(void) {
    vector<int> v = {1, 52, 6, 7, 8, 23};

    // reducer랑 같다.
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << sum << endl;

    vector<int>::iterator mIt = max_element(v.begin(), v.end());
    cout << *mIt << endl;

    vector<int>::iterator minIt = min_element(v.begin(), v.end());
    cout << *minIt << endl;
}