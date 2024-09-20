#include <bits/stdc++.h>
using namespace std;

int64_t a, b, c, p;

int64_t solve(int e) {
    if (e == 1) return a % c;

    p = solve(e / 2);
    if (e % 2)
        return (p % c * p % c * a % c) % c;
    else
        return (p % c * p % c) % c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;

    cout << solve(b);

    return 0;
}