#include <bits/stdc++.h>
using namespace std;

deque<int> dq;

void moveLeft() {
    dq.push_back(dq.front());
    dq.pop_front();
}

void moveRight() {
    dq.push_front(dq.back());
    dq.pop_back();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N, M;
    int u;
    int left, right;
    int ans = 0;

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) dq.push_back(i);
    while (M--) {
        cin >> u;
        left = right = 0;

        while (dq.front() != u) {
            moveLeft();
            ++left;
        }
        for (int i = 0; i < left; ++i) moveRight();
        while (dq.front() != u) {
            moveRight();
            ++right;
        }
        for (int i = 0; i < right; ++i) moveLeft();

        if (left < right) {
            ans += left;
            for (int i = 0; i < left; ++i) moveLeft();
        } else {
            ans += right;
            for (int i = 0; i < right; ++i) moveRight();
        }

        dq.pop_front();
    }

    cout << ans;

    return 0;
}