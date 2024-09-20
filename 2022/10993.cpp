#include <bits/stdc++.h>
using namespace std;

char grid[1023][2045];

void display(int n, int y, int x, int dir) {
    if (n == 1) {
        grid[y][x] = '*';
        return;
    }
    int height = (1 << n) - 1;
    int width = 2 * height - 1;
    if (dir == 1) {
        grid[y][x] = '*';
        for (int i = 1; i <= height - 2; ++i)
            grid[y + i][x - i] = grid[y + i][x + i] = '*';
        for (int i = 0; i < width; ++i)
            grid[y + height - 1][x - width / 2 + i] = '*';
    } else {
        grid[y][x] = '*';
        for (int i = 1; i <= height - 2; ++i)
            grid[y - i][x - i] = grid[y - i][x + i] = '*';
        for (int i = 0; i < width; ++i)
            grid[y - height + 1][x - width / 2 + i] = '*';
    }
    display(n - 1, y + dir * (height - 2), x, -dir);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int N;
    int height, width;

    cin >> N;
    if (N == 1)
        cout << '*';
    else {
        for (int i = 0; i < 1023; ++i)
            for (int j = 0; j < 2045; ++j) grid[i][j] = ' ';
        height = (1 << N) - 1;
        width = 2 * height - 1;
        if (N % 2) {
            display(N, 0, width / 2, 1);
            for (int i = 0; i < height; ++i) {
                for (int j = 0; j <= width / 2 + i; ++j) cout << grid[i][j];
                cout << '\n';
            }
        } else {
            display(N, height - 1, width / 2, -1);
            for (int i = 0; i < height; ++i) {
                for (int j = 0; j < width - i; ++j) cout << grid[i][j];
                cout << '\n';
            }
        }
    }

    return 0;
}