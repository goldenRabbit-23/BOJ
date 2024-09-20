#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> grid(N, vector<int>(N));
    vector<vector<int64_t>> dp(N, vector<int64_t>(N, 0));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> grid[i][j];

    dp[0][0] = 1;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] > 0) {
                if (i + grid[i][j] < N)
                    dp[i + grid[i][j]][j] += dp[i][j];
                if (j + grid[i][j] < N)
                    dp[i][j + grid[i][j]] += dp[i][j];
            }
        }
    }

    cout << dp[N - 1][N - 1];

    return 0;
}