#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    // 다 읽고 읽기에 실패하면 while을 벗어남.
    while (cin >> n) {
        cout << n << "\n";
    }

    // 마지막 읽고나서 eof가 true가 됨.
    // 따라서 마지막 값이 n에 들어 있기는 하나 출력되지는 않음.
    while (!(cin >> n).eof()) {
        cout << n << "\n";
    }
}