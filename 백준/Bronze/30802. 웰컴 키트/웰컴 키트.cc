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

    int N, T, P;
    vector<int> sizes(6);

    cin >> N;
    for (auto &size : sizes)
        cin >> size;
    cin >> T >> P;

    int shirts = accumulate(sizes.begin(), sizes.end(), 0,
                            [T](int sum, int size) -> int { return sum + (size + T - 1) / T; });

    cout << shirts << '\n' << N / P << ' ' << N % P << '\n';

    return 0;
}