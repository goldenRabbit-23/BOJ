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

const int MAX = 1000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    cin >> A >> B;

    int Q = A / B, R = A % B;
    cout << Q << '.';

    for (int i = 0; i < MAX; i++) {
        R *= 10;
        Q = R / B;
        R = R % B;
        cout << Q;
    }

    return 0;
}