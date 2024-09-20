#include <bits/stdc++.h>
using namespace std;

queue<int> q;
vector<int> g[501];
int d[501];
int ans = 0;

void bfs(int u) {
    q.push(u);
    d[1] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int p : g[v]) {
            if (d[p] == -1) {
                d[p] = d[v] + 1;
                if (d[p] <= 2) ++ans;
                q.push(p);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int n, m;
    int u, v;

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(d, -1, sizeof(d));
    bfs(1);

    cout << ans;

    return 0;
}