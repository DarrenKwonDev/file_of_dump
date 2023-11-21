#include <bits/stdc++.h>

using namespace std;

int intervalSum(vector<int>& p_sum, int start, int end) {
    return p_sum[end + 1] - p_sum[start];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> p_sum(n + 1);
    p_sum[0] = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        p_sum[i + 1] = p_sum[i] + tmp;
    }

    int start = 0;
    int end = 0;
    int cnt = 0;
    while (end <= n and start <= n) {
        if (intervalSum(p_sum, start, end) > m) {
            start++;
        } else if (intervalSum(p_sum, start, end) < m) {
            end++;
        } else {
            cnt++;
            end++;
        }
    }

    cout << cnt;
}