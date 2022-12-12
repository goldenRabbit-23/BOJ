#include <bits/stdc++.h>
using namespace std;

char v[15];
int vow = 0, con = 0;
string p = "";

bool vowel(char e) {
    if (e == 'a' || e == 'e' || e == 'i' || e == 'o' || e == 'u')
        return true;
    else
        return false;
}

void perm(int c, int l) {
    if (l == 0) {
        if (vow >= 1 && con >= 2) {
            for (int i = 0; i < (int)p.size(); ++i) cout << p[i];
            cout << '\n';
        }
        return;
    }
    for (int i = 0; i < c; ++i) {
        if (p[p.size() - 1] < v[i]) {
            bool isVow = vowel(v[i]);
            if (isVow)
                ++vow;
            else
                ++con;
            p += v[i];
            perm(c, l - 1);
            p.pop_back();
            if (isVow)
                --vow;
            else
                --con;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int L, C;

    cin >> L >> C;
    for (int i = 0; i < C; ++i) cin >> v[i];

    sort(v, v + C);
    perm(C, L);

    return 0;
}