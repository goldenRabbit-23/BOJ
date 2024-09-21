#include <algorithm>
#include <array>
#include <bitset>
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
    int ID, N, P, Q;
    cin >> ID;

    auto dec_to_bin = [](int n) -> string {
        bitset<32> binary(n);
        string str = binary.to_string();
        str.erase(0, str.find_first_of('1'));
        return str;
    };

    auto bin_to_dec = [](string s) -> int {
        int res = 0;
        for (int bit = 0; bit < int(s.size()); bit++)
            res += (s[bit] - '0') * (1 << bit);
        return res;
    };

    if (ID == 1) {
        cin >> N;

        if (N == 1) {
            cout << "1 1" << '\n';
            return;
        }

        string str = dec_to_bin(N);
        int p = 1, q = 1;

        for (int bit = 1; bit < int(str.size()); bit++) {
            if (str[bit] == '0')
                q += p;
            else
                p += q;
        }

        cout << p << ' ' << q << '\n';
    } else {
        cin >> P >> Q;

        int p = P, q = Q;
        string bin_idx;

        while (p > 1 || q > 1) {
            if (p < q) {
                q -= p;
                bin_idx += '0';
            } else {
                p -= q;
                bin_idx += '1';
            }
        }

        bin_idx += '1';

        /* bin_idx: binary reversed */
        cout << bin_to_dec(bin_idx) << '\n';
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