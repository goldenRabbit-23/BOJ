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
#include <stack>
#include <string>
#include <vector>
using namespace std;

void run_case() {
    int ID;
    cin >> ID;

    if (ID == 1) {
        uint64_t N;
        cin >> N;
        stack<int> bits;

        while (N > 0) {
            bits.push(N & 1);
            N >>= 1;
        }

        uint64_t p = 1, q = 1;

        bits.pop();
        while (!bits.empty()) {
            int bit = bits.top(); bits.pop();

            if (bit == 0)
                q += p;
            else
                p += q;
        }

        cout << p << ' ' << q << '\n';
    } else {
        uint64_t p, q;
        cin >> p >> q;
        uint64_t bitN = 1, N = 0;

        while (p > 1 || q > 1) {
            if (p < q) {
                q -= p;
            } else {
                p -= q;
                N += bitN;
            }

            bitN <<= 1;
        }

        N += bitN;
        cout << N << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        cout << "Case #" << tc << ": ";
        run_case();
    }

    return 0;
}