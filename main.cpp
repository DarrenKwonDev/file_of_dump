#include <bits/stdc++.h>
#define fio()                \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
typedef long long ll;
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int board[100][100] = {
    0,
};

int bfs_vis[101] = {
    0,
};

void bfs(int r, int c) {
    bfs_vis[r] = 1;
    queue<int> q;
    q.push(r);

    while (!q.empty()) {
        int here = q.front();
        q.pop();
        for (int nei : board[here]) {
            if (nei != 0 and !bfs_vis[nei]) {
                q.push(nei);
                bfs_vis[nei] = bfs_vis[here] + 1;
            }
        }
    }
}

int main() {
    fio();

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            int is_conn = str[j] - '0';
            if (is_conn != 0) {
                board[i][j] = 1;
            }
        }
    }

    bfs(0, 0);

    for (int i = 0; i < 102; i++) {
        cout << bfs_vis[i] << " ";
    }
}
