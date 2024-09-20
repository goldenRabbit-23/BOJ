#include <bits/stdc++.h>
using namespace std;

vector<int> tree[100001];

int dfs(int u) {
    int e = 0;
    if (tree[u][0] == -1 && tree[u][1] == -1) return 0;
    if (tree[u][0] != -1) e += dfs(tree[u][0]) + 1;
    if (tree[u][1] != -1) e += dfs(tree[u][1]) + 1;
    return e;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N;
    int a, b, c;
    int edges;
    int right = 0;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b >> c;
        tree[a].push_back(b);
        tree[a].push_back(c);
    }

    edges = dfs(1);

    int u = 1;
    while (tree[u][1] != -1) {
        ++right;
        u = tree[u][1];
    }

    cout << 2 * edges - right;

    return 0;
}