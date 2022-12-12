#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int off, on;
    int cur = 0, max = 0;
    int stn = 10;
    while (stn--) {
        cin >> off >> on;
        cur -= off;
        cur += on;
        if (max < cur) max = cur;
    }
    cout << max;

    return 0;
}