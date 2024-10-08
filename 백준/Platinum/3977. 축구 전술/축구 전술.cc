#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> SCC;
vector<int> g[100000];
stack<int> s;
int node_no[100000];
bool processed[100000];
int scc_id[100000];
int in_deg_scc[100000];
int cur_node_id;
int cur_scc_id;
int starting_scc_id;

void reset() {
    SCC.clear();
    for (int i = 0; i < N; ++i)
        g[i].clear();
    memset(node_no, 0, sizeof(node_no));
    memset(scc_id, -1, sizeof(scc_id));
    memset(processed, 0, sizeof(processed));
    memset(in_deg_scc, 0, sizeof(in_deg_scc));
    cur_node_id = 0;
    cur_scc_id = -1;
    starting_scc_id = -1;
}

int dfs(int u) {
    node_no[u] = ++cur_node_id;
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

        ++cur_scc_id;
        while (1) {
            int top = s.top();
            s.pop();
            scc.push_back(top);
            scc_id[top] = cur_scc_id;
            processed[top] = 1;
            if (top == u)
                break;
        }

        SCC.push_back(scc);
    }

    return parent;
}

void find_scc() {
    for (int i = 0; i < N; ++i)
        if (node_no[i] == 0)
            dfs(i);
}

void count_indegree() {
    for (int u = 0; u < N; ++u)
        for (int v : g[u])
            if (scc_id[u] != scc_id[v])
                ++in_deg_scc[scc_id[v]];
}

void find_starting_point() {
    for (int scc = 0; scc < int(SCC.size()); ++scc) {
        if (in_deg_scc[scc] == 0) {
            if (starting_scc_id == -1)
                starting_scc_id = scc;
            else {
                cout << "Confused\n";
                return;
            }
        }
    }

    sort(SCC[starting_scc_id].begin(), SCC[starting_scc_id].end());
    for (int u : SCC[starting_scc_id])
        cout << u << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    int u, v;

    cin >> T;
    while (T--) {
        reset();

        cin >> N >> M;
        for (int i = 0; i < M; ++i) {
            cin >> u >> v;
            g[u].push_back(v);
        }

        find_scc();
        count_indegree();
        find_starting_point();

        cout << '\n';
    }

    return 0;
}