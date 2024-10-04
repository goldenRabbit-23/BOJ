#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
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

    int N, D;
    cin >> N >> D;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    vector<int> Q(N);

    for (int i = 0; i < N; i++)
        Q[i] = A[i] / D;

    sort(Q.begin(), Q.end());

    int64_t i = 0, j = 0;
    int64_t ans = 0;

    while (i < N) {
        while (j < N && Q[i] == Q[j])
            j++;

        ans += (j - i) * (j - i - 1) / 2;
        i = j;
    }

    cout << ans << '\n';

    return 0;
}