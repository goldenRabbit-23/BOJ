#include <bits/stdc++.h>
using namespace std;

int V, E;
vector<vector<int>> SCC;
vector<int> g[10001];
stack<int> s;
int node_no[10001];
bool processed[10001];
int cur_id = 0;

int dfs(int u) {
    node_no[u] = ++cur_id;
    s.push(u);

    int parent = node_no[u];

    for (int v : g[u]) {
        if (node_no[v] == 0)
            parent = min(parent, dfs(v));
        else if (!processed[v])
            parent = min(parent, node_no[v]);
    }

    if (parent == node_no[u]) {
        vector<int> scc;

        while (1) {
            int top = s.top();
            s.pop();
            scc.push_back(top);
            processed[top] = 1;
            if (top == u)
                break;
        }

        SCC.push_back(scc);
    }

    return parent;
}

void find_scc() {
    for (int i = 1; i <= V; ++i)
        if (node_no[i] == 0)
            dfs(i);

    for (int i = 0; i < int(SCC.size()); ++i)
        sort(SCC[i].begin(), SCC[i].end());
    sort(SCC.begin(), SCC.end());

    cout << SCC.size() << '\n';
    for (int i = 0; i < int(SCC.size()); ++i) {
        for (int j = 0; j < int(SCC[i].size()); ++j)
            cout << SCC[i][j] << ' ';
        cout << "-1\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int u, v;

    cin >> V >> E;
    for (int i = 0; i < E; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
    }

    find_scc();

    return 0;
}