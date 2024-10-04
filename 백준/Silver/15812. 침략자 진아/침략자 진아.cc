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

const int INF = int(1e9) + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<string> grid(N);

    for (auto &row : grid)
        cin >> row;

    vector<pair<int, int>> houses;

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            if (grid[r][c] == '1')
                houses.emplace_back(r, c);

    vector<pair<int, int>> start_points;

    auto infect = [&]() -> int {
        auto [r1, c1] = start_points[0];
        auto [r2, c2] = start_points[1];
        int max_elapsed = 0;

        for (auto [r, c] : houses) {
            int min_elapsed_each = INF;
            min_elapsed_each = min(min_elapsed_each, abs(r - r1) + abs(c - c1));
            min_elapsed_each = min(min_elapsed_each, abs(r - r2) + abs(c - c2));
            max_elapsed = max(max_elapsed, min_elapsed_each);
        }

        return max_elapsed;
    };

    int ans = INF;

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