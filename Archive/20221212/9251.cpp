#include <bits/stdc++.h>
using namespace std;

int lcs[1001][1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    int i, j;

    cin >> s1 >> s2;
    for (i = 0; i < (int)s1.size(); ++i) {
        for (j = 0; j < (int)s2.size(); ++j) {
            if (s1[i] == s2[j])
                lcs[i + 1][j + 1] = lcs[i][j] + 1;
            else
                lcs[i + 1][j + 1] = max(lcs[i][j + 1], lcs[i + 1][j]);
        }
    }
    cout << lcs[i][j];

    return 0;
}