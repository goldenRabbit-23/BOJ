#include <bits/stdc++.h>
using namespace std;

int n;
map<string, int> m;

void track() {
    string name, status;

    while (n--) {
        cin >> name >> status;

        if (status == "enter")
            m[name] = 1;
        else
            m[name] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    track();

    for (auto it = m.rbegin(); it != m.rend(); ++it)
        if (it->second == 1)
            cout << it->first << '\n';

    return 0;
}