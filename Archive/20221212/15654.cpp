#include <bits/stdc++.h>
using namespace std;

int v[8];
bool c[8];
vector<int> p;

void perm(int n, int m) {
    if (m == 0) {
        for (int i = 0; i < (int)p.size(); ++i) {
            cout << p[i];
            if (i < (int)p.size() - 1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!c[i]) {
            p.push_back(v[i]);
            c[i] = 1;
            perm(n, m - 1);
            c[i] = 0;
            p.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N, M;

    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> v[i];

    sort(v, v + N);
    perm(N, M);

    return 0;
}