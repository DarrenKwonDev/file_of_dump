#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool eratosthenes[1000];
vector<ll> p;

void linear_sieve(int n) {
    memset(eratosthenes, 1, sizeof(eratosthenes));
    for (int i = 2; i <= n; i++) {
        if (eratosthenes[i]) {
            p.push_back(i);
        }
        for (auto j : p) {
            if (i * j > n)
                break;
            eratosthenes[i * j] = 0;
            if (i % j == 0)
                break;
        }
    }
}

int main(void) {
    linear_sieve(1000);

    for (int i = 2; i < 1000; i++) {
        if (eratosthenes[i]) {
            cout << i << " ";
        }
    }
}