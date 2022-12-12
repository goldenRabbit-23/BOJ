#include <bits/stdc++.h>
using namespace std;

struct loc {
    int z;
    int y;
    int x;
};

queue<loc> q;
int tomato[100][100][100];
int days[100][100][100];
int N, M, H;
int unriped = 0;
int ans = 0;

/* north, east, south, west, up, down */
const int z_dir[6] = {0, 0, 0, 0, +1, -1};
const int y_dir[6] = {+1, 0, -1, 0, 0, 0};
const int x_dir[6] = {0, +1, 0, -1, 0, 0};

void bfs() {
    while (!q.empty()) {
        loc u = q.front();
        q.pop();
        for (int i = 0; i < 6; ++i) {
            int dz = u.z + z_dir[i];
            int dy = u.y + y_dir[i];
            int dx = u.x + x_dir[i];
            if (dz >= 0 && dz < H && dy >= 0 && dy < N && dx >= 0 && dx < M) {
                if (tomato[dz][dy][dx] == 0) {
                    tomato[dz][dy][dx] = 1;
                    days[dz][dy][dx] = days[u.z][u.y][u.x] + 1;
                    ans = days[dz][dy][dx];
                    --unriped;
                    q.push({dz, dy, dx});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> M >> N >> H;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == 0) ++unriped;
                if (tomato[i][j][k] == 1) q.push({i, j, k});
            }
        }
    }

    bfs();

    if (unriped)
        cout << -1;
    else
        cout << ans;

    return 0;
}