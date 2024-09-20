#include <bits/stdc++.h>
using namespace std;

vector<int> tree[10001];
int check[10001];
int depth[10001];
int parent[10001][15];

void dfs(int cur, int prev) {
    depth[cur] = depth[prev] + 1;
    parent[cur][0] = prev;
    for (int c : tree[cur])
        dfs(c, cur);
}

void sparse(int n) {
    for (int i = 1; i < 15; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (parent[j][i - 1] != -1)
                parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
}

void lca(int u, int v) {
    if (depth[u] > depth[v])
        swap(u, v);

    int diff = depth[v] - depth[u];

    for (int i = 0; i < 15; ++i)
        if ((diff >> i) & 1)
            v = parent[v][i];

    if (u == v) {
        cout << u << '\n';
        return;
    }

    for (int i = 14; i >= 0; --i) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    cout << parent[u][0] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, N = 0;
    int u, v;

    cin >> T;
    while (T--) {
        for (int i = 1; i <= N; ++i) tree[i].clear();
        memset(check, -1, sizeof(check));
        memset(depth, 0, sizeof(depth));
        memset(parent, -1, sizeof(parent));

        cin >> N;
        for (int i = 0; i < N - 1; ++i) {
            cin >> u >> v;
            tree[u].push_back(v);
            check[v] = u;
        }

        for (int i = 1; i <= N; ++i) {
            if (check[i] == -1) {
                dfs(i, 0);
                break;
            }
        }

        sparse(N);

        cin >> u >> v;
        lca(u, v);
    }

    return 0;
}