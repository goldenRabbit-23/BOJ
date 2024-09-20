#include <bits/stdc++.h>
using namespace std;

int height[500][500];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N, M, B;
    int min = 256;
    int max = 0;
    int diff;
    int buildTime, digTime;
    int totalTime;
    int ansTime = (int)1e9;
    int ansHeight = 0;

    cin >> N >> M >> B;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) cin >> height[i][j];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (min > height[i][j]) min = height[i][j];
            if (max < height[i][j]) max = height[i][j];
        }
    }
    for (int i = min; i <= max; ++i) {
        buildTime = digTime = 0;
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                diff = i - height[j][k];
                if (diff > 0)
                    buildTime += diff;
                else if (diff < 0)
                    digTime += -diff;
            }
        }
        if (B + digTime >= buildTime) {
            totalTime = digTime * 2 + buildTime;
            if (ansTime >= totalTime) {
                ansTime = totalTime;
                ansHeight = i;
            }
        }
    }

    cout << ansTime << ' ' << ansHeight;

    return 0;
}