#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define ALPHABET_LEN (26)

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    vector<int> v_a(ALPHABET_LEN, 0);
    vector<int> v_b(ALPHABET_LEN, 0);

    cin >> a >> b;

    int a_size = a.size();
    int b_size = b.size();

    int i;
    for (i = 0; i < a_size; i++) {
        v_a[a[i] - 'a'] += 1;
    }
    for (i = 0; i < b_size; i++) {
        v_b[b[i] - 'a'] += 1;
    }
    int cnt = 0;
    for (i = 0; i < ALPHABET_LEN; i++) {
        if (v_a[i] != v_b[i]) {
            cnt += abs(v_a[i] - v_b[i]);
        }
    }

    cout << cnt;

    return 0;
}