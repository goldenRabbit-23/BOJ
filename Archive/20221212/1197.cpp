#include <bits/stdc++.h>
using namespace std;

struct edge {
    int weight;
    int src;
    int dest;
    bool operator<(const edge &other) {
        if (weight == other.weight && src == other.src)
            return dest < other.dest;
        else if (weight == other.weight)
            return src < other.src;
        else
            return weight < other.weight;
    }
};

vector<edge> edges;
int parent[10001];
int member[10001];
int V, E;
int ans = 0;

int find_root(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find_root(parent[u]);
}

void union_root(int u, int v) {
    int p = find_root(u);
    int q = find_root(v);

    if (p != q) {
        if (member[p] < member[q]) {
            parent[p] = q;
            member[q] += member[p];
        } else {
            parent[q] = p;
            member[p] += member[q];
        }
    }
}

void kruskal() {
    int cur = 0;

    for (edge &e : edges) {
        int w = e.weight;
        int x = e.src;
        int y = e.dest;

        if (find_root(x) != find_root(y)) {
            union_root(x, y);
            ++cur;
            ans += w;
        }

        if (cur == V - 1) break;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int a, b, c;

    cin >> V >> E;
    for (int i = 0; i < E; ++i) {
        cin >> a >> b >> c;
        edges.push_back({c, a, b});
    }

    for (int i = 1; i <= V; ++i) {
        parent[i] = i;
        member[i] = 0;
    }

    sort(edges.begin(), edges.end());

    kruskal();

    cout << ans;

    return 0;
}