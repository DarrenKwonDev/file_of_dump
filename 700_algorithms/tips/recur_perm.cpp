#include <bits/stdc++.h>

using namespace std;

vector<int> v = {1, 2, 3};

// permutation. nPk
void printAllPerm(int n, int k, int depth) {

    if (k == depth) {
        for (auto value : v) {
            cout << value << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = depth; i < n; i++) {
        swap(v[i], v[depth]);
        printAllPerm(n, k, depth + 1);
        swap(v[i], v[depth]);
    }

    return;
}

int main(void) {
    printAllPerm(3, 3, 0);
}