#include <bits/stdc++.h>
using namespace std;

vector<int> tree[100001];
int depth[100001];
int parent[100001][18];

void dfs(int cur, int prev) {
    depth[cur] = depth[prev] + 1;
    parent[cur][0] = prev;
    for (int i = 0; i < (int)tree[cur].size(); ++i) {
        if (tree[cur][i] != prev) dfs(tree[cur][i], cur);
    }
    return;
}

void sparse(int n) {
    for (int i = 1; i < 18; ++i) {
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
    for (int i = 0; i < 18; ++i) {
        if ((dif >> i) & 1) v = parent[v][i];
    }
    if (u == v) return u;
    for (int i = 17; i >= 0; --i) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

void odd(int a, int b, int c) {
    if (a != b && b == c)
        cout << a << '\n';
    else if (a != b && a == c)
        cout << b << '\n';
    else
        cout << c << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N, M;
    int r, u, v;
    int a, b, c;

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
        cin >> r >> u >> v;
        a = lca(r, u);
        b = lca(r, v);
        c = lca(u, v);
        odd(a, b, c);
    }

    return 0;
}