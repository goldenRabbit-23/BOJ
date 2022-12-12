#include <bits/stdc++.h>
using namespace std;

vector<int> g[201];
bool vis[201];
int match_cow[201];

bool dfs(int u) {
    if (vis[u])
        return false;

    vis[u] = 1;
    for (int v : g[u]) {
        if (!match_cow[v] || dfs(match_cow[v])) {
            match_cow[v] = u;
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    int n, k;
    int ans = 0;

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> n;
        for (int j = 0; j < n; ++j) {
            cin >> k;
            g[i].push_back(k);
        }
    }

    for (int i = 1; i <= N; ++i) {
        memset(vis, 0, sizeof(vis));
        if (dfs(i))
            ++ans;
    }

    cout << ans;

    return 0;
}