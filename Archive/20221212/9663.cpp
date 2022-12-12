#include <bits/stdc++.h>
using namespace std;

int col[14];
int N;
int ans = 0;

bool valid(int c) {
    for (int i = 0; i < c; ++i) {
        if (col[i] == col[c] || c - i == abs(col[c] - col[i])) return false;
    }
    return true;
}

void nqueen(int c) {
    if (c >= N) ++ans;
    for (int i = 0; i < N; ++i) {
        col[c] = i;
        if (valid(c)) nqueen(c + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> N;
    nqueen(0);
    cout << ans;

    return 0;
}