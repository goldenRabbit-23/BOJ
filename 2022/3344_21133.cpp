#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N;
    bool odd = false;

    cin >> N;

    if (N % 2) odd = true;
    if ((!odd && N % 6 != 2) || (odd && (N - 1) % 6 != 2)) {
        if (odd) --N;
        for (int i = 1; i <= N / 2; ++i) cout << 2 * i << '\n';
        for (int i = 1; i <= N / 2; ++i) cout << 2 * i - 1 << '\n';
        if (odd) cout << N + 1 << '\n';
    } else if ((!odd && N % 6 != 0) || (odd && (N - 1) % 6 != 0)) {
        if (odd) --N;
        for (int i = 1; i <= N / 2; ++i)
            cout << 1 + (2 * (i - 1) + N / 2 - 1) % N << '\n';
        for (int i = N / 2; i > 0; --i)
            cout << N - (2 * (i - 1) + N / 2 - 1) % N << '\n';
        if (odd) cout << N + 1 << '\n';
    }

    return 0;
}