#include <bits/stdc++.h>
using namespace std;

int dp[2][1001];

int min3(int a, int b, int c) { return min(min(a, b), c); }

void editDist(string& x, string& y, int m, int n) {
    for (int p = 0; p <= n; ++p) dp[0][p] = p;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (j == 0)
                dp[i % 2][j] = i;
            else if (x[i - 1] == y[j - 1])
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1];
            else
                dp[i % 2][j] = 1 + min3(dp[(i - 1) % 2][j], dp[i % 2][j - 1],
                                        dp[(i - 1) % 2][j - 1]);
        }
    }
    cout << dp[m % 2][n] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int m, n;
    string X, Y;

    memset(dp, -1, sizeof(dp));
    cin >> X >> Y;
    m = (int)X.size();
    n = (int)Y.size();
    editDist(X, Y, m, n);

    return 0;
}