#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int d[100001];

void bfs(int n, int k) {
    q.push(n);
    while (d[k] == -1) {
        int f = q.front();
        q.pop();
        for (int nxt : {f - 1, f + 1, f * 2}) {
            if (nxt >= 0 && nxt <= 100000) {
                if (d[nxt] == -1) {
                    d[nxt] = d[f] + 1;
                    q.push(nxt);
                }
            }
        }
    }
    cout << d[k];
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N, K;

    memset(d, -1, sizeof(d));
    cin >> N >> K;
    d[N] = 0;
    bfs(N, K);

    return 0;
}