#include <bits/stdc++.h>
using namespace std;

bool paper[128][128];
int N;
int white = 0, blue = 0;

void divide(int p, int q, int n) {
    bool flag = true;
    if (n == 1) {
        if (!paper[p][q])
            ++white;
        else
            ++blue;
        return;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (paper[p + i][q + j] != paper[p][q]) {
                flag = false;
                break;
            }
        }
    }
    if (flag) {
        if (!paper[p][q])
            ++white;
        else
            ++blue;
    } else {
        divide(p, q, n / 2);
        divide(p, q + n / 2, n / 2);
        divide(p + n / 2, q, n / 2);
        divide(p + n / 2, q + n / 2, n / 2);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) cin >> paper[i][j];
    }

    divide(0, 0, N);

    cout << white << '\n' << blue;

    return 0;
}