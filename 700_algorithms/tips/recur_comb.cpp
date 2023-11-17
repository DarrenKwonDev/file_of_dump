#include <bits/stdc++.h>

using namespace std;

vector<char> v = {'a', 'b', 'c'};
int n = 3;
int k = 2;

void printAllComb(int start, vector<int> holder) {
    if (holder.size() == k) {
        for (auto idx : holder) {
            cout << v[idx] << " ";
        }
        cout << "\n";
    }
    for (int i = start + 1; i < n; i++) {
        holder.push_back(i);
        printAllComb(i, holder);
        holder.pop_back();
    }
}

int main(void) {
    vector<int> holder;
    printAllComb(-1, holder);
}