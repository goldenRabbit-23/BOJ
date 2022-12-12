#include <bits/stdc++.h>
using namespace std;

int depth[1024];
int parent[1024][11];

void dfs(int cur, int prev) {
    if (cur >= 1024) return;
    depth[cur] = depth[prev] + 1;
    parent[cur][0] = prev;
    dfs(cur * 2, cur);
    dfs(cur * 2 + 1, cur);
    return;
}

void sparse(int n) {
    for (int i = 1; i < 11; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (parent[j][i - 1] != -1)
                parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
    return;
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    int dif = depth[v] - depth[u];
    for (int i = 0; i < 11; ++i) {
        if ((dif >> i) & 1) v = parent[v][i];
    }
    if (u == v) return u;
    for (int i = 10; i >= 0; --i) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int T;
    int u, v;

    memset(parent, -1, sizeof(parent));
    dfs(1, 0);
    sparse(1023);

    cin >> T;
    while (T--) {
        cin >> u >> v;
        cout << lca(u, v) * 10 << '\n';
    }

    return 0;
}