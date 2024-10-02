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

    int x1, x2, a, b, c, d, e;
    cin >> x1 >> x2 >> a >> b >> c >> d >> e;
    cout << (a / 3) * (x2 * x2 * x2 - x1 * x1 * x1)
          + ((b - d) / 2) * (x2 * x2 - x1 * x1)
          + (c - e) * (x2 - x1) << '\n';

    return 0;
}