#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

// North, East, West, South
const int DR[] = {-1, 0, 0, 1};
const int DC[] = {0, 1, -1, 0};

const int INF = int(1e9) + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<string> grid(N);

    for (auto &row : grid)
        cin >> row;

    int houses = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (grid[i][j] == '1')
                houses++;

    int ans = INF;
    vector<pair<int, int>> start_points;

    auto infect = [&]() -> int {
        auto [r1, c1] = start_points[0];
        auto [r2, c2] = start_points[1];
        vector<vector<int>> time_grid(N, vector<int>(M, INF));
        time_grid[r1][c1] = time_grid[r2][c2] = 0;
        queue<pair<int, int>> q;
        q.push({r1, c1}); q.push({r2, c2});
        int infected = 0, elapsed = 0;

        while (infected < houses && !q.empty()) {
            auto [r, c] = q.front(); q.pop();

            for (int d = 0; d < 4; d++) {
                int nr = r + DR[d];
                int nc = c + DC[d];

                // out of bounds
                if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                    continue;

                // already visited
                if (time_grid[nr][nc] < INF)
                    continue;

                // update neighbor cell infection time
                elapsed = time_grid[nr][nc] = time_grid[r][c] + 1;
                q.push({nr, nc});

                if (grid[nr][nc] == '1')
                    infected++;
            }
        }

        return elapsed;
    };

    // cell_n ∈ [0, N * M - 1]
    y_combinator([&](auto self, int prev, int cnt) -> void {
        if (cnt == 2) {
            ans = min(ans, infect());
            return;
        }

        for (int next = prev + 1; next < N * M; next++) {
            int r = next / M;
            int c = next - r * M;

            if (grid[r][c] == '1')
                continue;

            start_points.emplace_back(r, c);
            self(next, cnt + 1);
            start_points.pop_back();
        }
    })(-1, 0);

    cout << ans << '\n';

    return 0;
}