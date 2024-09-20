#include <bits/stdc++.h>
using namespace std;

string fib[10001] = {"0", "1"};

string add_big_number(string p, string q) {
    string res = "";
    int digit_sum = 0;

    while (!p.empty() || !q.empty() || digit_sum > 0) {
        if (!p.empty()) {
            digit_sum += p.back() - '0';
            p.pop_back();
        }

        if (!q.empty()) {
            digit_sum += q.back() - '0';
            q.pop_back();
        }

        res += (digit_sum % 10) + '0';
        digit_sum /= 10;
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    if (n > 1) {
        for (int i = 2; i <= n; ++i)
            fib[i] = add_big_number(fib[i - 1], fib[i - 2]);
    }

    cout << fib[n];

    return 0;
}