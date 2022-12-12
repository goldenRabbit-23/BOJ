#include <bits/stdc++.h>
using namespace std;

queue<int> q;
vector<vector<int>> g;
bool vis[101];
int inf = 0;

void bfs(int u) {
    q.push(u);
    vis[u] = true;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = 0; i < (int)g[t].size(); ++i) {
            if (!vis[g[t][i]]) {
                vis[g[t][i]] = true;
                ++inf;
                q.push(g[t][i]);
            }
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int n, m;
    int u, v;

    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs(1);
    cout << inf;

    return 0;
}