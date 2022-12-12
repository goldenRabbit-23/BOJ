#include <bits/stdc++.h>
using namespace std;

bool mat[100][100];

void solve(int n) {
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (mat[i][k] && mat[k][j]) mat[i][j] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << mat[i][j] << ' ';
        cout << '\n';
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N;

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) cin >> mat[i][j];

    solve(N);

    return 0;
}