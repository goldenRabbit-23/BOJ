#include <bits/stdc++.h>
using namespace std;

int n[100001];
int sum[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N, M;
    int i, j;

    cin >> N;
    for (int p = 1; p <= N; ++p) {
        cin >> n[p];
        sum[p] = sum[p - 1] + n[p];
    }
    cin >> M;
    while (M--) {
        cin >> i >> j;
        cout << sum[j] - sum[i - 1] << '\n';
    }

    return 0;
}