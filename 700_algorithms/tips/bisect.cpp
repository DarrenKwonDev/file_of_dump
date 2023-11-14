#include <bits/stdc++.h>

using namespace std;

int main(void) {
    vector<int> sorted_v = {1, 4, 5, 5, 5, 6};

    // bisect.bisect_left
    cout << lower_bound(sorted_v.begin(), sorted_v.end(), 5) - sorted_v.begin() << endl; // 2

    // bisect.bisect_right
    cout << upper_bound(sorted_v.begin(), sorted_v.end(), 5) - sorted_v.begin() << endl; // 5

    // 아, 5가 3개 있구나.
    cout << upper_bound(sorted_v.begin(), sorted_v.end(), 5) - lower_bound(sorted_v.begin(), sorted_v.end(), 5) << endl;

    // 100은 없지만 정렬되게 넣으려면 6번재 인덱스에 넣어야 하는구나. (upper_bound 또한 동일한 값을 반환하겠구나)
    cout << lower_bound(sorted_v.begin(), sorted_v.end(), 100) - sorted_v.begin() << endl; // 6
}