#include <bits/stdc++.h>
using namespace std;

int grid[9][9];
int maxVal = 0;
pair<int, int> loc = {1, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> grid[i][j];
            if (maxVal < grid[i][j]) {
                maxVal = grid[i][j];
                loc.first = i + 1;
                loc.second = j + 1;
            }
        }
    }

    cout << maxVal << '\n' << loc.first << ' ' << loc.second;

    return 0;
}