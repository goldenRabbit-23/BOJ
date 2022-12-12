#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int>> q;
char maze[100][100];
bool vis[100][100];
int dis[100][100];

/* north, east, south, west */
const int x_dir[4] = {0, +1, 0, -1};
const int y_dir[4] = {+1, 0, -1, 0};

void bfs(int r, int c) {
    dis[0][0] = 1;
    vis[0][0] = true;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        pair<int, int> next = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int y_coord = next.first + y_dir[i];
            int x_coord = next.second + x_dir[i];
            if (x_coord >= 0 && x_coord < c && y_coord >= 0 && y_coord < r) {
                if (maze[y_coord][x_coord] == '1') {
                    if (!vis[y_coord][x_coord]) {
                        vis[y_coord][x_coord] = true;
                        dis[y_coord][x_coord] =
                            dis[next.first][next.second] + 1;
                        q.push(make_pair(y_coord, x_coord));
                    }
                }
            }
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N, M;
    char c;

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            while ((c = cin.get()) == '\n')
                ;
            maze[i][j] = c;
        }
    }

    bfs(N, M);

    cout << dis[N - 1][M - 1];

    return 0;
}