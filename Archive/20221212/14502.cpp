#include <bits/stdc++.h>
using namespace std;

int lab[8][8];
bool vis[8][8];
int N, M;
int safe = 0;
int cur, ans = 0;

/* north, east, south, west */
const int x_dir[4] = {0, +1, 0, -1};
const int y_dir[4] = {+1, 0, -1, 0};

int dfs(int p, int q) {
    int infected = 0;
    if (lab[p][q] == 0) {
        ++infected;
        vis[p][q] = 1;
    }
    for (int i = 0; i < 4; ++i) {
        int dy = p + y_dir[i];
        int dx = q + x_dir[i];
        if (dy >= 0 && dy < N && dx >= 0 && dx < M) {
            if (lab[dy][dx] == 0 && !vis[dy][dx]) infected += dfs(dy, dx);
        }
    }
    return infected;
}

int countSafe() {
    int remain = safe;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (lab[i][j] == 2) remain -= dfs(i, j);
        }
    }
    return remain;
}

void putWall(int w) {
    if (w == 3) {
        memset(vis, 0, sizeof(vis));
        cur = countSafe();
        if (ans < cur) ans = cur;
        return;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (lab[i][j] == 0) {
                lab[i][j] = 1;
                putWall(w + 1);
                lab[i][j] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> lab[i][j];
            if (lab[i][j] == 0) ++safe;
        }
    }

    safe -= 3;
    putWall(0);
    cout << ans << '\n';

    return 0;
}