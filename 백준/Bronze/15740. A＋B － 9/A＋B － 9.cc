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

struct BigInt {
    bool negative;
    string value;

    BigInt() : negative(false), value("") {}
};

ostream &operator<<(ostream &os, const BigInt &X) {
    return os << (X.negative ? "-" : "") << X.value;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    BigInt A, B;
    cin >> A.value >> B.value;

    auto add = [&](string &a, string &b) -> string {
        int a_len = int(a.size()), b_len = int(b.size());
        int max_len = max(a_len, b_len);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        if (a_len < b_len)
            a += string(b_len - a_len, '0');
        else if (a_len > b_len)
            b += string(a_len - b_len, '0');

        string res = "";
        int carry = 0, sum_of_digits;

        for (int i = 0; i < max_len; i++) {
            sum_of_digits = (a[i] - '0') + (b[i] - '0') + carry;
            res += (sum_of_digits % 10) + '0';
            carry = sum_of_digits / 10;
        }

        if (carry == 1)
            res += '1';

        reverse(res.begin(), res.end());
        return res;
    };

    auto sub = [&](string &a, string &b) -> string {
        int a_len = int(a.size()), b_len = int(b.size());
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        b += string(a_len - b_len, '0');
        string res = "";
        int borrow = 0, diff_of_digits;

        for (int i = 0; i < a_len; i++) {
            diff_of_digits = (a[i] - '0') - (b[i] - '0') - borrow;
            if (diff_of_digits < 0) {
                diff_of_digits += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            res += diff_of_digits + '0';
        }

        reverse(res.begin(), res.end());
        res.erase(0, res.find_first_not_of('0'));
        return res;
    };

    auto greater = [](string &a, string &b) -> bool {
        if (a.size() != b.size())
            return a.size() > b.size();
        return a > b;
    };

    if (A.value[0] == '-') {
        A.negative = true;
        A.value = A.value.substr(1);
    }

    if (B.value[0] == '-') {
        B.negative = true;
        B.value = B.value.substr(1);
    }

    BigInt ans;

    if (!A.negative && !B.negative) {        // A >= 0, B >= 0
        ans.value = add(A.value, B.value);
    } else if (A.negative && B.negative) {   // A < 0, B < 0
        ans.negative = true;
        ans.value = add(A.value, B.value);
    } else if (!A.negative && B.negative) {  // A >= 0, B < 0
        if (greater(A.value, B.value)) {  // |A| > |B|
            ans.value = sub(A.value, B.value);
        } else {  // |A| <= |B|
            ans.negative = true;
            ans.value = sub(B.value, A.value);
        }
    } else if (A.negative && !B.negative) {  // A < 0, B >= 0
        if (greater(A.value, B.value)) {  // |A| > |B|
            ans.negative = true;
            ans.value = sub(A.value, B.value);
        } else {  // |A| <= |B|
            ans.value = sub(B.value, A.value);
        }
    }

    cout << ans << '\n';

    return 0;
}