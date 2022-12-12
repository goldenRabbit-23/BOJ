#include <bits/stdc++.h>
using namespace std;

int T, N;
queue<pair<int, int>> q;
int cave[125][125];
int rupee[125][125];

/* North, East, South, West */
const int dir_R[] = {-1, 0, +1, 0};
const int dir_C[] = {0, +1, 0, -1};

void bfs() {
    q.push({0, 0});

    while (!q.empty()) {
        pair<int, int> next_rupee = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = next_rupee.first + dir_R[i];
            int nc = next_rupee.second + dir_C[i];
            if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
                if (rupee[nr][nc] >
                    rupee[next_rupee.first][next_rupee.second] + cave[nr][nc]) {
                    rupee[nr][nc] = rupee[next_rupee.first][next_rupee.second] +
                                    cave[nr][nc];
                    q.push({nr, nc});
                }
            }
        }
    }
}

void run_case(int test_case) {
    bfs();

    cout << "Problem " << test_case << ": " << rupee[N - 1][N - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc = 0;

    while (++tc) {
        cin >> N;
        if (N == 0) break;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> cave[i][j];
                rupee[i][j] = int(1e9);
            }
        }

        rupee[0][0] = cave[0][0];

        run_case(tc);
    }

    return 0;
}