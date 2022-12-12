#include <bits/stdc++.h>
using namespace std;

stack<int> st;
int seq[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    string ans = "";
    int n;
    int cur;
    int p;
    bool flag;

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> seq[i];

    cur = 1;
    p = 1;
    flag = true;
    while (cur <= n) {
        st.push(cur++);
        ans += '+';
        while (!st.empty() && st.top() == seq[p]) {
            st.pop();
            ans += '-';
            ++p;
        }
    }
    while (!st.empty()) {
        if (st.top() != seq[p]) {
            flag = false;
            break;
        }
        st.pop();
        ans += '-';
        ++p;
    }

    if (flag) {
        for (int i = 0; i < (int)ans.size(); ++i) {
            cout << ans[i];
            if (i < (int)ans.size() - 1) cout << '\n';
        }
    } else
        cout << "NO";

    return 0;
}