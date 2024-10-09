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

const int64_t END = int64_t(1e18);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    int64_t low = -END, high = END;
    bool maybe_got = false, paradox = false;
    int maybe_got_query = 0;

    for (int q = 1; q <= Q; q++) {
        int64_t x;
        char comp;
        cin >> x >> comp;

        // after paradox, queries after doesn't matter
        if (paradox)
            continue;

        if (comp == '^') {
            low = max(low, x + 1);
        } else if (comp == 'v') {
            high = min(high, x - 1);
        }

        // paradox found
        if (low > high) {
            paradox = true;
            cout << "Paradox!" << '\n'
                 << q << '\n';
        }

        // if number found, store the query # tentatively
        if (!maybe_got && low == high) {
            maybe_got = true;
            maybe_got_query = q;
        }
    }

    if (!paradox) {
        if (maybe_got) {
            cout << "I got it!" << '\n'
                 << maybe_got_query << '\n';
        } else {
            cout << "Hmm..." << '\n';
        }
    }

    return 0;
}