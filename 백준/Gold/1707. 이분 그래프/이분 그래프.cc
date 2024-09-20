#include <bits/stdc++.h>
using namespace std;

vector<int> g[20001];
int color[20001];
bool is_bipartite;

void bfs(int u, int c) {
    queue<int> q;

    q.push(u);
    color[u] = c;

    while (!q.empty()) {
        int t = q.front();
        q.pop();

        for (int v : g[t]) {
            if (color[v] == 0) {
                color[v] = -color[t];
                q.push(v);
            } else if (color[t] + color[v] != 0) {
                is_bipartite = 0;
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K, V = 0, E;
    int u, v;

    cin >> K;
    while (K--) {
        for (int i = 1; i <= V; ++i)
            g[i].clear();
        memset(color, 0, sizeof(color));
        is_bipartite = 1;

        cin >> V >> E;
        for (int i = 0; i < E; ++i) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        for (int i = 1; i <= V; ++i) {
            if (color[i] == 0)
                bfs(i, 1);

            if (!is_bipartite) {
                cout << "NO\n";
                break;
            }
        }

        if (is_bipartite)
            cout << "YES\n";
    }

    return 0;
}