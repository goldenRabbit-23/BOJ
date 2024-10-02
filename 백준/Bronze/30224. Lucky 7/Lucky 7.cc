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

    auto contain_7 = [](int n) -> bool {
        string s = to_string(n);
        return s.find('7') != string::npos;
    };

    if (!contain_7(N)) {
        cout << (N % 7 != 0 ? 0 : 1) << '\n';
    } else {
        cout << (N % 7 != 0 ? 2 : 3) << '\n';
    }

    return 0;
}