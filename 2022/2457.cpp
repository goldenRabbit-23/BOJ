#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N;
    int a, b, c, d;
    int curDate = 301, curIdx = 0, updatedDate = 0;
    int ans = 0;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b >> c >> d;
        if (100 * a + b <= 1130 || 100 * c + d > 301)
            v.push_back({100 * a + b, 100 * c + d});
    }

    sort(v.begin(), v.end());

    while (curDate <= 1130) {
        for (int i = curIdx; i < (int)v.size(); ++i) {
            if (v[i].first > curDate) break;
            if (v[i].second > updatedDate) {
                updatedDate = v[i].second;
                curIdx = i;
            }
        }
        if (curDate == updatedDate) {
            ans = 0;
            break;
        }
        curDate = updatedDate;
        ++ans;
    }

    cout << ans;

    return 0;
}