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

    int N;
    cin >> N;
    vector<int> H(N + 2, 0);

    for (int i = 1; i <= N; i++)
        cin >> H[i];

    int64_t ans = N * 2;

    for (int i = 1; i <= N; i++)
        ans += H[i] * 2;

    for (int i = 0; i <= N; i++)
        ans += abs(H[i] - H[i + 1]);

    cout << ans << '\n';

    return 0;
}