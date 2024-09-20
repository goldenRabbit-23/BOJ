#include <bits/stdc++.h>
using namespace std;

int N;
stack<pair<int, int>> s;

void solve() {
    int height;

    for (int i = 1; i <= N; ++i) {
        cin >> height;

        while (!s.empty()) {
            if (s.top().first > height) {
                cout << s.top().second << ' ';
                break;
            }
            s.pop();
        }

        if (s.empty())
            cout << "0 ";

        s.push({height, i});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    solve();

    return 0;
}