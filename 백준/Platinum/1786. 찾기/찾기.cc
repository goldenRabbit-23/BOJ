#include <bits/stdc++.h>
using namespace std;

string T, P;
int pi[1000000];
vector<int> pos;
int cnt = 0;

void evaluate() {
    int len = P.size();
    int i = 1, j = 0;

    while (i < len) {
        while (j > 0 && P[i] != P[j])
            j = pi[j - 1];

        if (P[i] == P[j])
            pi[i] = ++j;

        ++i;
    }
}

void kmp() {
    int n = T.size();
    int m = P.size();

    for (int i = 0, j = 0; i < n; ++i) {
        while (j > 0 && T[i] != P[j])
            j = pi[j - 1];

        if (T[i] == P[j]) {
            if (j == m - 1) {
                ++cnt;
                pos.push_back(i - m + 2);
                j = pi[j];
            } else
                ++j;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, T);
    getline(cin, P);

    evaluate();
    kmp();

    cout << cnt << '\n';
    for (auto it = pos.begin(); it != pos.end(); ++it)
        cout << *it << ' ';

    return 0;
}