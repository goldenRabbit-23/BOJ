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

    int N;
    cin >> N;

    if (N == 0) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> difficulty(N);

    for (auto &d : difficulty)
        cin >> d;

    sort(difficulty.begin(), difficulty.end());

    int cutoff = int(round(N * 0.15));
    int sum = accumulate(difficulty.begin() + cutoff, difficulty.end() - cutoff, 0);

    cout << round(sum / double(N - 2 * cutoff)) << '\n';

    return 0;
}