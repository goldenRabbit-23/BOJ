#include <bits/stdc++.h>
using namespace std;

vector<int> tree[50];
bool vis[50];
int cnt = 0;

void dfs(int u) {
    if (vis[u]) return;
    bool isLeaf = true;
    vis[u] = 1;
    for (int i = 0; i < (int)tree[u].size(); ++i) {
        if (!vis[tree[u][i]]) {
            dfs(tree[u][i]);
            isLeaf = false;
        }
    }
    if (isLeaf) ++cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N, D;
    int p;
    int root;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> p;
        if (p == -1)
            root = i;
        else
            tree[p].push_back(i);
    }
    cin >> D;
    vis[D] = 1;

    dfs(root);
    cout << cnt;

    return 0;
}