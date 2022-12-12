#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 1;

int N;
int A[11], op_cnt[4], op[10];
int res_min = INF, res_max = -INF;

int apply_op(int a, int b, int op) {
    if (op == 0)
        return a + b;
    else if (op == 1)
        return a - b;
    else if (op == 2)
        return a * b;
    else if (op == 3)
        return a / b;

    assert(false);
}

void solve() {
    int res;

    do {
        res = A[0];
        for (int i = 1; i < N; ++i) res = apply_op(res, A[i], op[i - 1]);
        if (res_min > res) res_min = res;
        if (res_max < res) res_max = res;
    } while (next_permutation(op, op + N - 1));

    cout << res_max << '\n' << res_min;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k = 0;

    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < 4; ++i) {
        cin >> op_cnt[i];
        for (int j = 0; j < op_cnt[i]; ++j) op[j + k] = i;
        k += op_cnt[i];
    }

    solve();

    return 0;
}