#include <bits/stdc++.h>

using namespace std;

int main(void) {

    int a, b;
    pair<int, int> p = make_pair(1, 1);
    tie(a, b) = p;
    cout << a << " " << b;

    int x, y, z;
    tuple<int, int, int> t = make_tuple(1, 2, 3);
    tie(x, y, z) = t;
    cout << x << y << z;

    return 0;
}