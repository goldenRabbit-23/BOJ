#include <iostream>
using namespace std;

int main() {
    int N, K;
    int i = 1;
    bool flag = false;

    cin >> N >> K;
    while (i <= N) {
        if (N % i == 0) {
            --K;
            if (K == 0) {
                flag = true;
                cout << i;
                break;
            }
        }
        ++i;
    }
    if (!flag) cout << 0;

    return 0;
}