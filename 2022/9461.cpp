#include <bits/stdc++.h>
using namespace std;

long long pad[101] = {0, 1, 1, 1, 2, 2};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int T, N;
    int u = 6;

    cin >> T;
    while (T--) {
        cin >> N;
        if (pad[N])
            cout << pad[N] << '\n';
        else {
            for (int i = u; i <= N; ++i) pad[i] = pad[i - 1] + pad[i - 5];
            cout << pad[N] << '\n';
            u = N;
        }
    }

    return 0;
}