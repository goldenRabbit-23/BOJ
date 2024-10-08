#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    vector<string> grid(N);

    for (auto &row : grid)
        cin >> row;

    vector<vector<char>> ans_grid(K, vector<char>(K));
    int tile_row = N / K, tile_col = M / K;
    int tiles = tile_row * tile_col;

    auto most_alphabet = [&](int r, int c) -> int {
        vector<int> freq(26, 0);
        int max_freq = 0;
        char max_freq_alphabet = 'A';

        for (int tr = 0; tr < tile_row; tr++) {
            for (int tc = 0; tc < tile_col; tc++) {
                char alphabet = grid[tr * K + r][tc * K + c];
                freq[alphabet - 'A']++;

                if (max_freq < freq[alphabet - 'A']) {
                    max_freq = freq[alphabet - 'A'];
                    max_freq_alphabet = alphabet;
                }
            }
        }

        ans_grid[r][c] = max_freq_alphabet;
        return max_freq;
    };

    int ans = 0;

    for (int r = 0; r < K; r++)
        for (int c = 0; c < K; c++)
            ans += tiles - most_alphabet(r, c);

    cout << ans << '\n';

    for (int tr = 0; tr < tile_row; tr++) {
        for (int r = 0; r < K; r++) {
            for (int tc = 0; tc < tile_col; tc++)
                for (int c = 0; c < K; c++)
                    cout << ans_grid[r][c];
            cout << '\n';
        }
    }

    return 0;
}