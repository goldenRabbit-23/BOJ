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
    vector<int> H(N);

    for (auto &h : H)
        cin >> h;

    vector<int> sorted = H;
    sort(sorted.begin(), sorted.end());
    int diff = 0;

    for (int i = 0; i < N; i++)
        diff += H[i] != sorted[i];

    cout << (diff > 0 ? diff - 1 : 0) << '\n';

    return 0;
}