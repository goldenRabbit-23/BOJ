#include <bits/stdc++.h>
using namespace std;

string S;
map<string, int> m;
int ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int len;
    string p;

    cin >> S;

    len = S.size();
    for (int i = 0; i < len; ++i) {
        p = "";
        for (int j = i; j < len; ++j) {
            p += S[j];
            if (!m[p]) {
                ++ans;
                m[p] = 1;
            }
        }
    }

    cout << ans;

    return 0;
}