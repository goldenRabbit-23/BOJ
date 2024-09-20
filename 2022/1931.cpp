#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N;
    int s, e;
    int last_end = 0;
    int res = 0;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> s >> e;
        v.push_back({e, s});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < (int)v.size(); ++i) {
        if (v[i].second >= last_end) {
            last_end = v[i].first;
            ++res;
        }
    }

    cout << res;

    return 0;
}