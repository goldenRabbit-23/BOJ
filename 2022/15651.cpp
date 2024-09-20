#include <bits/stdc++.h>
using namespace std;

string p = "";

void perm(int n, int m) {
    if (m == 0) {
        for (int i = 0; i < (int)p.size(); ++i) {
            cout << p[i];
            if (i < (int)p.size() - 1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; ++i) {
        p += i + '0';
        perm(n, m - 1);
        p.pop_back();
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M;

    cin >> N >> M;
    perm(N, M);

    return 0;
}