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

const int INF = int(1e9) + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t A, B;
    cin >> A >> B;

    map<int64_t, int> ops;
    ops[A] = 1;

    queue<int64_t> q;
    q.push(A);

    while (!q.empty()) {
        int64_t now = q.front(); q.pop();

        if (now == B)
            continue;

        int64_t opt1 = now * 2, opt2 = now * 10 + 1;

        if (opt1 <= B && ops.find(opt1) == ops.end())
            ops[opt1] = INF;
        if (opt2 <= B && ops.find(opt2) == ops.end())
            ops[opt2] = INF;

        if (opt1 <= B && ops[now] + 1 < ops[opt1]) {
            ops[opt1] = ops[now] + 1;
            q.push(opt1);
        }
        if (opt2 <= B && ops[now] + 1 < ops[opt2]) {
            ops[opt2] = ops[now] + 1;
            q.push(opt2);
        }
    }

    cout << (ops.find(B) == ops.end() ? -1 : ops[B]) << '\n';

    return 0;
}