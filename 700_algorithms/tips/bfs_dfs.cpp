#include <bits/stdc++.h>
#define fio()                \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
typedef long long ll;
using namespace std;

int dfs_visit[1001] = {
    0,
};
int bfs_visit[1001] = {
    0,
};
vector<int> adj[1001];

void dfs(int node) {
    cout << node << " ";
    dfs_visit[node] = 1;
    for (auto& nei : adj[node]) {
        if (nei != 0 and !dfs_visit[nei]) {
            dfs(nei);
        }
    }
}

void bfs(int node) {
    bfs_visit[node] = 1;
    queue<int> q;
    q.push(node);
    while (!q.empty()) {
        int here = q.front();
        cout << here << " ";
        q.pop();
        for (auto nei : adj[here]) {
            if (bfs_visit[nei]) {
                continue;
            }
            bfs_visit[nei] = 1;
            q.push(nei);
        }
    }
}

int main() {
    fio();

    int n, m, v;
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;

        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    // dfs
    dfs(v);

    cout << "\n";

    // bfs
    bfs(v);
}
