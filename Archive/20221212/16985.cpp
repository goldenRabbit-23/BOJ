#include <bits/stdc++.h>
using namespace std;

struct loc {
    int z;
    int y;
    int x;
};

const int INF = (int)1e9;

queue<loc> q;
int input[5][5][5], maze[5][5][5], tmp[5][5][5];
int order[5] = {0, 1, 2, 3, 4};
int dist[5][5][5];
int ans = INF;

/* north, east, south, west, up, down */
const int z_dir[6] = {0, 0, 0, 0, +1, -1};
const int y_dir[6] = {+1, 0, -1, 0, 0, 0};
const int x_dir[6] = {0, +1, 0, -1, 0, 0};

void bfs() {
    memset(dist, -1, sizeof(dist));
    if (maze[0][0][0] == 1 && maze[4][4][4] == 1) {
        dist[0][0][0] = 0;
        q.push({0, 0, 0});
    }
    while (!q.empty()) {
        loc u = q.front();
        q.pop();
        for (int i = 0; i < 6; ++i) {
            int dz = u.z + z_dir[i];
            int dy = u.y + y_dir[i];
            int dx = u.x + x_dir[i];
            if (dz >= 0 && dz < 5 && dy >= 0 && dy < 5 && dx >= 0 && dx < 5) {
                if (dist[dz][dy][dx] == -1 && maze[dz][dy][dx] == 1) {
                    dist[dz][dy][dx] = dist[u.z][u.y][u.x] + 1;
                    q.push({dz, dy, dx});
                }
            }
        }
    }

    /* exit immediately */
    if (dist[4][4][4] == 12) {
        cout << 12;
        exit(0);
    }
    if (dist[4][4][4] != -1) ans = min(ans, dist[4][4][4]);
}

void construct() {
    sort(order, order + 5);
    do {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                for (int k = 0; k < 5; ++k)
                    maze[order[i]][j][k] = input[i][j][k];
            }
        }
        bfs();
    } while (next_permutation(order, order + 5));
}

void rotate(int h) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) tmp[h][i][j] = input[h][i][j];
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) input[h][j][4 - i] = tmp[h][i][j];
    }
}

void solve(int n) {
    if (n == 5) {
        construct();
        return;
    }
    for (int i = 0; i < 4; ++i) {
        rotate(n);
        solve(n + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) cin >> input[i][j][k];
        }
    }

    solve(0);

    if (ans == INF)
        cout << -1;
    else
        cout << ans;

    return 0;
}