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

void run_case() {
    int N;
    cin >> N;
    string name, type;
    map<string, int> clothes;

    for (int i = 0; i < N; i++) {
        cin >> name >> type;
        clothes[type]++;
    }

    int combs = 1;

    for (auto &[type, cnt] : clothes)
        combs *= cnt + 1;

    cout << combs - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        run_case();

    return 0;
}