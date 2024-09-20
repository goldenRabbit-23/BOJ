#include <bits/stdc++.h>
using namespace std;

int N, M;
int64_t cum_sum[1000001];
int64_t remain[1000];
int64_t ans = 0;

void solve() {
    ++remain[0];
    for (int i = 1; i <= N; ++i) {
        cum_sum[i] += cum_sum[i - 1];
        ++remain[cum_sum[i] % M];
    }

    for (int i = 0; i < M; ++i) {
        if (remain[i] > 1)
            ans += remain[i] * (remain[i] - 1) / 2;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        cin >> cum_sum[i];

    solve();

    cout << ans;

    return 0;
}