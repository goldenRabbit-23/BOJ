#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
int compressed[1000000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N;
    int X;
    int p, cnt = 0;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> X;
        v.push_back({X, i});
    }

    sort(v.begin(), v.end());

    p = v[0].first;
    compressed[v[0].second] = 0;
    for (int i = 1; i < N; ++i) {
        if (v[i].first == p)
            compressed[v[i].second] = cnt;
        else {
            compressed[v[i].second] = ++cnt;
            p = v[i].first;
        }
    }

    for (int i = 0; i < N; ++i) cout << compressed[i] << ' ';

    return 0;
}