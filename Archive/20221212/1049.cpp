#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N, M;
    int six, one;
    int minSix = 1000, minOne = 1000;
    int ans = 0;

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> six >> one;
        minSix = min(minSix, six);
        minOne = min(minOne, one);
    }

    while (N) {
        if (N > 6) {
            if (minSix < minOne * 6)
                ans += minSix;
            else
                ans += minOne * 6;
            N -= 6;
        } else {
            if (minSix < minOne * N)
                ans += minSix;
            else
                ans += minOne * N;
            N = 0;
        }
    }

    cout << ans;

    return 0;
}