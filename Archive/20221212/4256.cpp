#include <bits/stdc++.h>
using namespace std;

int T, n;
int pre_order[1001], number_loc[1001];

void post_order(int start, int end, int root) {
    if (start > end)
        return;
    if (start == end) {
        cout << pre_order[root] << ' ';
        return;
    }

    int root_loc = number_loc[pre_order[root]];

    post_order(start, root_loc - 1, root + 1);
    post_order(root_loc + 1, end, root + 1 + root_loc - start);
    cout << pre_order[root] << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> pre_order[i];
        for (int i = 1; i <= n; ++i) {
            cin >> num;
            number_loc[num] = i;
        }

        post_order(1, n, 1);
        cout << '\n';
    }

    return 0;
}