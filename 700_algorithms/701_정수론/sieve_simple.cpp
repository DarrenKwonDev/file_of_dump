#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool eratosthenes[1000];

// n까지 소수를 찾는 에라토스테네스 체
void era(int n) {
    // 우선 전부 소수 가정.
    memset(eratosthenes, 1, sizeof(eratosthenes));

    for (int i = 2; i <= n; i++) {
        if (eratosthenes[i]) {
            for (int j = 2; i * j <= n; j++) {
                // 소수의 배수는 소수가 아니므로.
                eratosthenes[i * j] = 0;
            }
        }
    }
}

int main(void) {
    era(1000);

    for (int i = 2; i < 1000; i++) {
        if (eratosthenes[i]) {
            cout << i << " ";
        }
    }
}