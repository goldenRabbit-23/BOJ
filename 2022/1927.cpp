#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N;
    int x;

    cin >> N;
    while (N--) {
        cin >> x;
        if (x > 0)
            pq.push(x);
        else {
            if (!pq.empty()) {
                cout << pq.top() << '\n';
                pq.pop();
            } else
                cout << "0\n";
        }
    }

    return 0;
}