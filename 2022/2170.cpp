#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 1;
pair<int, int> line[1000000];
int N, x, y;

void solve() {
    int start = -INF, last = -INF;
    int ans = 0;

    for (int i = 0; i < N; ++i) {
        x = line[i].first;
        y = line[i].second;

        if (last < x) {
            ans += last - start;
            start = x;
        }

        last = max(last, y);
    }
    ans += last - start;

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        line[i].first = x;
        line[i].second = y;
    }

    sort(line, line + N);

    solve();

    return 0;
}