#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int>> q;
int tomato[1000][1000];
int days[1000][1000];
int N, M;
int unriped = 0;
int ans = 0;

/* north, east, south, west */
const int y_dir[4] = {+1, 0, -1, 0};
const int x_dir[4] = {0, +1, 0, -1};

void bfs() {
    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int dy = u.first + y_dir[i];
            int dx = u.second + x_dir[i];
            if (dy >= 0 && dy < N && dx >= 0 && dx < M) {
                if (tomato[dy][dx] == 0) {
                    tomato[dy][dx] = 1;
                    days[dy][dx] = days[u.first][u.second] + 1;
                    ans = days[dy][dx];
                    --unriped;
                    q.push({dy, dx});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> M >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 0) ++unriped;
            if (tomato[i][j] == 1) q.push({i, j});
        }
    }

    bfs();

    if (unriped)
        cout << -1;
    else
        cout << ans;

    return 0;
}