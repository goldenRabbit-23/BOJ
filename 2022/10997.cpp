#include <bits/stdc++.h>
using namespace std;

char grid[400][398];

void display(int n, int off) {
    if (n == 1) {
        grid[1 + off][1 + off] = '*';
        grid[2 + off][1 + off] = '*';
        grid[3 + off][1 + off] = '*';
        return;
    }

    for (int i = 1; i <= 4 * n - 3; ++i) {
        grid[1 + off][i + off] = '*';
        grid[1 + off + 4 * n - 2][i + off] = '*';
        grid[i + 1 + off][1 + off] = '*';
        grid[i + 1 + off][1 + off + 4 * n - 4] = '*';
    }
    grid[2 + off][1 + off + 4 * n - 4] = ' ';
    grid[3 + off][off + 4 * n - 4] = '*';

    display(n - 1, off + 2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int N;

    for (int i = 0; i < 400; ++i)
        for (int j = 0; j < 398; ++j) grid[i][j] = ' ';

    cin >> N;
    if (N > 1) display(N, 0);

    if (N == 1)
        cout << '*';
    else {
        for (int i = 1; i <= 4 * N - 1; ++i) {
            for (int j = 1; j <= 4 * N - 3; ++j) {
                if (i == 2) {
                    if (grid[2][j] == '*') cout << '*';
                } else
                    cout << grid[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}