#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string pwd;
    cin >> N >> pwd;

    vector<bool> check(4, false);

    for (char p : pwd) {
        if ('a' <= p && p <= 'z')
            check[0] = true;
        else if ('A' <= p && p <= 'Z')
            check[1] = true;
        else if ('0' <= p && p <= '9')
            check[2] = true;
        else
            check[3] = true;
    }

    int ans = 0;

    for (bool b : check)
        ans += !b;

    cout << ans + max(0, 6 - N - ans) << '\n';

    return 0;
}