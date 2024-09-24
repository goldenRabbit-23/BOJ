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

    int N, M;
    cin >> N >> M;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    vector<int> prefix_sum(N + 1, 0);

    for (int x = 1; x <= N; x++)
        prefix_sum[x] = prefix_sum[x - 1] + A[x - 1];

    int i, j;

    for (int x = 0; x < M; x++) {
        cin >> i >> j;
        cout << prefix_sum[j] - prefix_sum[i - 1] << '\n';
    }

    return 0;
}