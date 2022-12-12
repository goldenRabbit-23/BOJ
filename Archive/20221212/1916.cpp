#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int, int>> pq;
vector<pair<int, int>> g[1001];
int d[1001];

void dijkstra(int u) {
    d[u] = 0;
    pq.push({0, u});
    while (!pq.empty()) {
        int old_cost = -pq.top().first;
        int src = pq.top().second;
        pq.pop();
        if (old_cost > d[src]) continue;
        for (int i = 0; i < (int)g[src].size(); ++i) {
            int dest = g[src][i].first;
            int cost = g[src][i].second;
            if (d[dest] > d[src] + cost) {
                d[dest] = d[src] + cost;
                pq.push({-d[dest], dest});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N, M;
    int s, e, c;
    int A, B;

    memset(d, 0x7f, sizeof(d));
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> s >> e >> c;
        g[s].push_back({e, c});
    }

    cin >> A >> B;
    dijkstra(A);
    cout << d[B];

    return 0;
}