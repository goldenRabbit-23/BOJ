#include <bits/stdc++.h>
using namespace std;

int v[20];
int N, S;
int ans = 0;

void solve(int c, int s) {
    if (c == N) {
        if (s == S) ++ans;
        return;
    }
    solve(c + 1, s);
    solve(c + 1, s + v[c]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> N >> S;
    for (int i = 0; i < N; ++i) cin >> v[i];

    solve(0, 0);

    if (S == 0) --ans;
    cout << ans;

    return 0;
}