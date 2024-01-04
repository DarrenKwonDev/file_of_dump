#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

#define fio()                                                                                                          \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
typedef unsigned long long ll;
using namespace std;

vector<ll> genFiboSeq(ll max) {
    assert(max > 0);          // max must be positive
    assert(max <= LLONG_MAX); // max must be less than or equal to LLONG_MAX

    vector<ll> fiboSeq = {1, 2};

    while (true) {
        ll fibNum = fiboSeq[fiboSeq.size() - 1] + fiboSeq[fiboSeq.size() - 2];
        if (fibNum > max) {
            fiboSeq.push_back(fibNum); // push the last one
            break;
        }
        fiboSeq.push_back(fibNum);
    }

    return fiboSeq; // RVO. don't worry about performance
}

ll summation(vector<ll>& seq, ll a, ll b) {
    assert(a >= 0 && b >= 0); // a and b must be positive
    assert(a <= b);           // a must be less than or equal to b

    ll tot = 0;
    for (auto num : seq) {
        if (num >= a && num <= b) {
            tot += num;
        }
    }
    return tot;
}

int main(void) {
    fio();

    ll a = 12345678999;
    ll b = 99987654321;

    auto fiboSeq = genFiboSeq(b);
    ll ans = summation(fiboSeq, a, b);

    std::cout << ans << "\n";

    return 0;
}
