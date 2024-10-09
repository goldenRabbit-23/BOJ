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

    int orig_hp, new_digit;
    cin >> orig_hp >> new_digit;

    auto is_prime = [](int n) -> bool {
        if (n % 2 == 0)
            return false;

        for (int d = 3; d * d < n; d += 2)
            if (n % d == 0)
                return false;

        return true;
    };

    if (!is_prime(orig_hp)) {
        cout << "No" << '\n';
        return 0;
    }

    if (!is_prime(new_digit * int(1e6) + orig_hp)) {
        cout << "No" << '\n';
        return 0;
    }

    cout << "Yes" << '\n';
    return 0;
}