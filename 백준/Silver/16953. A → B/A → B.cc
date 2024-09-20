#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t A, B;
    cin >> A >> B;

    queue<pair<int64_t, int>> q;
    q.push({A, 1});

    while (!q.empty()) {
        auto [now, cnt] = q.front(); q.pop();

        if (now == B) {
            cout << cnt << '\n';
            return 0;
        }

        int64_t opt1 = now * 2, opt2 = now * 10 + 1;

        if (opt1 <= B)
            q.push({opt1, cnt + 1});
        if (opt2 <= B)
            q.push({opt2, cnt + 1});
    }

    cout << -1 << '\n';

    return 0;
}