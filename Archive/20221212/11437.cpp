#include <bits/stdc++.h>
using namespace std;

vector<int> tree[50001];
int depth[50001];
int parent[50001][17];

void dfs(int cur, int prev) {
    depth[cur] = depth[prev] + 1;
    parent[cur][0] = prev;
    for (int i = 0; i < (int)tree[cur].size(); ++i) {
        if (tree[cur][i] != prev) dfs(tree[cur][i], cur);
    }
    return;
}

void sparse(int n) {
    for (int i = 1; i < 17; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (parent[j][i - 1] != -1)
                parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
    return;
}

void lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    int dif = depth[v] - depth[u];
    for (int i = 0; i < 17; ++i) {
        if ((dif >> i) & 1) v = parent[v][i];
    }
    if (u == v) {
        cout << u << '\n';
        return;
    }
    for (int i = 16; i >= 0; --i) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    cout << parent[u][0] << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N, M;
    int u, v;

    memset(parent, -1, sizeof(parent));
    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 0);
    sparse(N);

    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        lca(u, v);
    }

    return 0;
}