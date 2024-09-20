#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, N;
    cin >> A >> B >> N;

    int q, r = A % B;

    while (N-- > 0) {
        A = r * 10;
        q = A / B;
        r = A % B;
    }

    cout << q << '\n';

    return 0;
}