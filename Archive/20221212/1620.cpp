#include <bits/stdc++.h>
using namespace std;

map<string, int> m;
string p[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N, M;
    string s;
    int k;

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> s;
        m[s] = i + 1;
        p[i + 1] = s;
    }
    for (int i = 0; i < M; ++i) {
        cin >> s;
        if (s[0] - '0' > 0 && s[0] - '0' <= 9) {
            k = stoi(s);
            cout << p[k] << '\n';
        } else {
            cout << m[s] << '\n';
        }
    }

    return 0;
}