#include <bits/stdc++.h>
using namespace std;

int word[50];
int learned;
int N, K;
int ans = 0;

void check() {
    int cur = 0;
    for (int i = 0; i < N; ++i)
        if ((word[i] & learned) == word[i]) ++cur;
    ans = max(ans, cur);
}

void learn(int c, int l) {
    if (c == 0) {
        check();
        return;
    }
    for (int i = l; i < 26; ++i) {
        if (!(learned & (1 << i))) {
            learned |= 1 << i;
            learn(c - 1, i + 1);
            learned &= ~(1 << i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    string w;

    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> w;
        for (int j = 0; j < (int)w.size(); ++j) word[i] |= 1 << (w[j] - 'a');
    }

    if (K < 5)
        ans = 0;
    else if (K == 26)
        ans = N;
    else {
        learned |= 1 << ('a' - 'a');
        learned |= 1 << ('c' - 'a');
        learned |= 1 << ('i' - 'a');
        learned |= 1 << ('n' - 'a');
        learned |= 1 << ('t' - 'a');
        learn(K - 5, 0);
    }

    cout << ans;

    return 0;
}