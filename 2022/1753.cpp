#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9;
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> v[20001];
int d[20001];
int V, E, K;

void dijkstra(int u) {
    d[u] = 0;
    pq.push({0, u});
    while (!pq.empty()) {
        int cur_cost = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        if (d[cur_node] < cur_cost) continue;
        for (auto &p : v[cur_node]) {
            if (d[p.first] > d[cur_node] + p.second) {
                d[p.first] = d[cur_node] + p.second;
                pq.push({-d[p.first], p.first});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int a, b, c;

    cin >> V >> E >> K;
    for (int i = 0; i < E; ++i) {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    for (int i = 1; i <= V; ++i) d[i] = INF;

    dijkstra(K);

    for (int i = 1; i <= V; ++i) {
        if (d[i] == INF)
            cout << "INF\n";
        else
            cout << d[i] << '\n';
    }

    return 0;
}