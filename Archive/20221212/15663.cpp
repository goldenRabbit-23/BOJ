#include <bits/stdc++.h>
using namespace std;

int v[8];
bool c[8];
vector<int> p = {0};

void perm(int s, int n, int m) {
    int tmp = 0;
    if (m == 0) {
        for (int i = 1; i < (int)p.size(); ++i) {
            cout << p[i];
            if (i < (int)p.size() - 1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = s; i < n; ++i) {
        if (!c[i] && v[i] != tmp && p.back() <= v[i]) {
            p.push_back(v[i]);
            c[i] = 1;
            tmp = v[i];
            perm(s + 1, n, m - 1);
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
    perm(0, N, M);

    return 0;
}