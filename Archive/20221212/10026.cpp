#include <bits/stdc++.h>
using namespace std;

char maze[100][100];
bool vis[100][100];

/* north, east, south, west */
const int x_dir[4] = {0, +1, 0, -1};
const int y_dir[4] = {+1, 0, -1, 0};

void dfsHuman(char c, int y, int x, int n) {
    vis[y][x] = true;
    for (int i = 0; i < 4; ++i) {
        int dy = y + y_dir[i];
        int dx = x + x_dir[i];
        if (dy >= 0 && dy < n && dx >= 0 && dx < n) {
            if (maze[dy][dx] == c) {
                if (!vis[dy][dx]) dfsHuman(c, dy, dx, n);
            }
        }
    }
}

void dfsCow(char c, int y, int x, int n) {
    vis[y][x] = true;
    for (int i = 0; i < 4; ++i) {
        int dy = y + y_dir[i];
        int dx = x + x_dir[i];
        if (dy >= 0 && dy < n && dx >= 0 && dx < n) {
            if (c == 'R' || c == 'G') {
                if (maze[dy][dx] == 'R' || maze[dy][dx] == 'G') {
                    if (!vis[dy][dx]) dfsCow(c, dy, dx, n);
                }
            } else {
                if (maze[dy][dx] == c) {
                    if (!vis[dy][dx]) dfsCow(c, dy, dx, n);
                }
            }
        }
    }
}

void humanPart(int n) {
    int part = 0;
    char cur;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!vis[i][j]) {
                ++part;
                cur = maze[i][j];
                dfsHuman(cur, i, j, n);
            }
        }
    }
    cout << part << ' ';
}

void cowPart(int n) {
    int part = 0;
    char cur;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!vis[i][j]) {
                ++part;
                cur = maze[i][j];
                dfsCow(cur, i, j, n);
            }
        }
    }
    cout << part;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N;
    char c;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            while ((c = cin.get()) == '\n')
                ;
            maze[i][j] = c;
        }
    }
    humanPart(N);
    memset(vis, 0, sizeof(vis));
    cowPart(N);

    return 0;
}