#include <bits/stdc++.h>
using namespace std;

string display;
int pi[1000000];

void evaluate() {
    int len = int(display.size());
    int i = 1, j = 0;

    while (i < len) {
        while (j > 0 && display[i] != display[j])
            j = pi[j - 1];

        if (display[i] == display[j])
            pi[i] = ++j;

        ++i;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int L;

    cin >> L >> display;

    evaluate();

    cout << L - pi[L - 1];

    return 0;
}