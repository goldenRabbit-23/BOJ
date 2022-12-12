#include <bits/stdc++.h>
using namespace std;

int wine[10000];
int dp[10000];
int N;

int max3(int a, int b, int c) { return max(max(a, b), c); }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) cin >> wine[i];

    dp[0] = wine[0];
    for (int i = 1; i < N; ++i)
        dp[i] = max3(dp[i - 1], dp[i - 2] + wine[i],
                     dp[i - 3] + wine[i - 1] + wine[i]);

    cout << dp[N - 1];

    return 0;
}