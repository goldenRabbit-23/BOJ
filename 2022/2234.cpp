#include <bits/stdc++.h>
using namespace std;

int N, M;
queue<pair<int, int>> q;
int castle[50][50];
bool vis[50][50];
int room_no[50][50];
int room_count[2500];
int current_room_no;
int max_room_size;
int max_room_size_after_remove;

/* West, North, East, South */
const int dir_R[] = {0, -1, 0, +1};
const int dir_C[] = {-1, 0, +1, 0};

void bfs_2(int r, int c) {
    int two_rooms_size_sum;

    q.push({r, c});
    vis[r][c] = 1;

    while (!q.empty()) {
        pair<int, int> next_room = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d) {
            int nr = next_room.first + dir_R[d];
            int nc = next_room.second + dir_C[d];
            if (nr >= 0 && nr < M && nc >= 0 && nc < N) {
                if (!vis[nr][nc]) {
                    if (room_no[next_room.first][next_room.second] ==
                        room_no[nr][nc]) {
                        q.push({nr, nc});
                        vis[nr][nc] = 1;
                    } else {
                        two_rooms_size_sum =
                            room_count[room_no[next_room.first]
                                              [next_room.second]] +
                            room_count[room_no[nr][nc]];
                        max_room_size_after_remove =
                            max(max_room_size_after_remove, two_rooms_size_sum);
                    }
                }
            }
        }
    }
}

void remove_wall() {
    memset(vis, 0, sizeof(vis));
    max_room_size_after_remove = 0;

    for (int r = 0; r < M; ++r) {
        for (int c = 0; c < N; ++c) {
            if (!vis[r][c]) bfs_2(r, c);
        }
    }
}

void bfs(int r, int c) {
    int room_cnt = 0;

    q.push({r, c});
    vis[r][c] = 1;
    room_no[r][c] = current_room_no;
    ++room_cnt;

    while (!q.empty()) {
        pair<int, int> next_room = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d) {
            int nr = next_room.first + dir_R[d];
            int nc = next_room.second + dir_C[d];
            if (nr >= 0 && nr < M && nc >= 0 && nc < N) {
                if (castle[next_room.first][next_room.second] & (1 << d))
                    continue;
                if (!vis[nr][nc]) {
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                    room_no[nr][nc] = current_room_no;
                    ++room_cnt;
                }
            }
        }
    }

    room_count[current_room_no] = room_cnt;
}

void explore() {
    current_room_no = -1;

    for (int r = 0; r < M; ++r) {
        for (int c = 0; c < N; ++c) {
            if (!vis[r][c]) {
                ++current_room_no;
                bfs(r, c);
                max_room_size = max(max_room_size, room_count[current_room_no]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int r = 0; r < M; ++r) {
        for (int c = 0; c < N; ++c) cin >> castle[r][c];
    }

    explore();

    cout << current_room_no + 1 << '\n' << max_room_size << '\n';

    remove_wall();

    cout << max_room_size_after_remove;

    return 0;
}