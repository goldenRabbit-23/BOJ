#include <bits/stdc++.h>
using namespace std;

string dp[101][101];

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

string combination(int n, int r) {
    if (r == 0 || n == r) return "1";
    if (dp[n][r] != "") return dp[n][r];
    return dp[n][r] =
               add_big_number(combination(n - 1, r - 1), combination(n - 1, r));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    cout << combination(n, m);

    return 0;
}