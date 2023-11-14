#include <bits/stdc++.h>

using namespace std;

int main(void) {

    vector<int> v = {1, 5, 7, 2, 8};

    sort(v.begin(), v.end()); // 오름차순

    sort(v.begin(), v.end(), greater<int>()); // 내림차순
    sort(v.begin(), v.end(), greater_equal<int>());

    sort(v.begin(), v.end(), less<int>()); // 오름 차순
    sort(v.begin(), v.end(), less_equal<int>());

    vector<pair<string, int>> pairV;
    pairV.push_back(make_pair("juju", 3));
    pairV.push_back(make_pair("juju", 10));
    pairV.push_back(make_pair("ann", 2));

    // first로 사전순, second로 오름차순.
    sort(pairV.begin(), pairV.end());

    for (auto& [name, age] : pairV) {
        cout << name << " " << age << "\n";
    }

    sort(pairV.begin(), pairV.end(), [](const pair<string, int> a, const pair<string, int> b) {
        if (a.first == b.first) {
            return a.second > b.second; // 내림 차순
        } else {
            return a.first < b.first; // 오름차순(사전식)
        }
    });

    for (auto& [name, age] : pairV) {
        cout << name << " " << age << "\n";
    }
}