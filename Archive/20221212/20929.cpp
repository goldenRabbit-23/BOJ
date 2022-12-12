#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N;
    int u, v;
    int la, lb, ra, rb;

    cin >> N;

    if (N == 1) {
        cout << "? A 1" << endl;
        cin >> u;
        cout << "? B 1" << endl;
        cin >> v;
        cout << "! " << min(u, v) << flush;
    } else {
        la = lb = 1;
        ra = rb = N;
        while (1) {
            if (la == ra && lb == rb) {
                cout << "? A " << la << endl;
                cin >> u;
                cout << "? B " << lb << endl;
                cin >> v;
                cout << "! " << min(u, v) << flush;
                break;
            }
            cout << "? A " << (la + ra) / 2 << endl;
            cin >> u;
            cout << "? B " << (lb + rb) / 2 << endl;
            cin >> v;
            if (u < v) {
                la = (la + ra) / 2 + 1;
                rb = (lb + rb) / 2;
            } else if (u > v) {
                ra = (la + ra) / 2;
                lb = (lb + rb) / 2 + 1;
            } else {
                cout << "! " << u << flush;
                break;
            }
        }
    }

    return 0;
}