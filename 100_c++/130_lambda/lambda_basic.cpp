#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<double> v = {1.1, 9.9, 2.2, 3.3, 8.8};

    // lambda 익명 함수
    // 오름차순 정렬
    sort(v.begin(), v.end(), [](double a, double b) { return a < b; });

    for (auto k : v) {
        cout << k << " ";
    }

    return 0;
}