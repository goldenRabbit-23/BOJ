#include <bits/stdc++.h>
using namespace std;

int n[500][500];
int dp[500][500];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) cin >> n[i][j];
    }

    for (int i = 0; i < N; ++i) dp[N - 1][i] = n[N - 1][i];
    for (int i = N - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j)
            dp[i][j] = n[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
    }
    cout << dp[0][0];

    return 0;
}