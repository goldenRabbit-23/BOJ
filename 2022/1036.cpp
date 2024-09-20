#include <bits/stdc++.h>
using namespace std;

struct inc_struct {
    int inc[60];
    bool operator<(const inc_struct &other) {
        for (int i = 59; i >= 0; --i) {
            if (inc[i] > other.inc[i]) return true;
            if (inc[i] < other.inc[i]) return false;
        }
        return false;
    }
} inc_tbl[36];
int ans[60];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int N, K;
    int len;
    char d;
    int c = 0;
    string num;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> num;
        len = (int)num.size();

        for (int j = 0; j < len; ++j) {
            d = num[len - j - 1];
            if (d < 'A') {
                ans[j] += d - '0';
                inc_tbl[d - '0'].inc[j] += '9' - d + 26;
            } else {
                ans[j] += d - 'A' + 10;
                inc_tbl[d - 'A' + 10].inc[j] += 'Z' - d;
            }
        }
    }

    for (int i = 0; i < 36; ++i) {
        for (int j = 0; j < 59; ++j) {
            inc_tbl[i].inc[j + 1] += inc_tbl[i].inc[j] / 36;
            inc_tbl[i].inc[j] %= 36;
        }
    }

    sort(inc_tbl, inc_tbl + 36);

    cin >> K;
    for (int i = 0; i < 59; ++i) {
        for (int j = 0; j < K; ++j) ans[i] += inc_tbl[j].inc[i];
        ans[i + 1] += ans[i] / 36;
        ans[i] %= 36;
        if (ans[i]) c = i;
    }

    do {
        if (ans[c] > 9)
            cout << (char)(ans[c] - 10 + 'A');
        else
            cout << ans[c];
    } while (--c >= 0);

    return 0;
}