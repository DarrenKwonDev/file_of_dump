#include <bits/stdc++.h>
#define fio()                \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
typedef long long ll;
using namespace std;

int visited[1000];
vector<int> adj[1000];
int ret = 0;

void dfs(int i) {
    visited[i] = 1;
    for (auto neighbor : adj[i]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    fio();

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // DFS
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            ret++;
            dfs(i);
        }
    }

    cout << ret;
}
