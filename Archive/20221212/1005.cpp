#include <bits/stdc++.h>
using namespace std;

queue<int> q;
vector<int> g[1001];
int d[1001];
int ind[1001];
int dp[1001];

void bfs() {
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            int new_cost = dp[u] + d[v];
            if (dp[v] < new_cost) dp[v] = new_cost;
            if (!(--ind[v])) q.push(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int T, N = 0, K, W;
    int u, v;

    cin >> T;
    while (T--) {
        for (int i = 1; i <= N; ++i) g[i].clear();
        memset(ind, 0, sizeof(ind));
        memset(dp, 0, sizeof(dp));

        cin >> N >> K;
        for (int i = 1; i <= N; ++i) cin >> d[i];
        for (int i = 0; i < K; ++i) {
            cin >> u >> v;
            g[u].push_back(v);
            ++ind[v];
        }
        cin >> W;

        for (int i = 1; i <= N; ++i) {
            if (!ind[i]) {
                q.push(i);
                dp[i] = d[i];
            }
        }
        bfs();
        cout << dp[W] << '\n';
    }

    return 0;
}