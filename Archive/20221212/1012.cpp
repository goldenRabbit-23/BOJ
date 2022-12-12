#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int>> q;
bool cab[500][500];
bool vis[500][500];

/* north, east, south, west */
const int x_dir[4] = {0, +1, 0, -1};
const int y_dir[4] = {+1, 0, -1, 0};

void bfs(int y, int x, int r, int c) {
    q.push({y, x});
    while (!q.empty()) {
        pair<int, int> f = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int dy = f.first + y_dir[i];
            int dx = f.second + x_dir[i];
            if (dy >= 0 && dy < r && dx >= 0 && dx < c) {
                if (cab[dy][dx] && !vis[dy][dx]) {
                    vis[dy][dx] = 1;
                    q.push({dy, dx});
                }
            }
        }
    }
}

void part(int n, int m) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (cab[i][j] && !vis[i][j]) {
                ++ans;
                bfs(i, j, n, m);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int T, M, N, K;
    int X, Y;

    cin >> T;
    while (T--) {
        memset(cab, 0, sizeof(cab));
        memset(vis, 0, sizeof(vis));
        cin >> M >> N >> K;
        while (K--) {
            cin >> X >> Y;
            cab[Y][X] = 1;
        }
        part(N, M);
    }

    return 0;
}