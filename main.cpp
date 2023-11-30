#include <bits/stdc++.h>
#define fio()                \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
typedef long long ll;
using namespace std;

int board[100][100] = {
    0,
};
int vis[100][100] = {
    0,
};
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int n, m;

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    vis[y][x] = 1;
    while (!q.empty()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 범위를 벗어나거나 이미 방문한 노드거나, 갈 수 없는 곳이라면 생략
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                continue;
            }
            if (board[ny][nx] == 0) {
                continue;
            }
            if (vis[ny][nx] != 0) {
                continue;
            }

            vis[ny][nx] = vis[y][x] + 1;

            q.push(make_pair(ny, nx));
        }
    }
}

int main() {
    fio();

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            int is_conn = str[j] - '0';
            if (is_conn) {
                board[i][j] = 1;
            }
        }
    }

    bfs(0, 0);

    cout << vis[n - 1][m - 1];

    return 0;
}
