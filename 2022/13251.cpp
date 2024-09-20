#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int pebble[50];
double each_pebble_prob;
double all_pebble_prob = 0.0;

void calculate() {
    for (int i = 0; i < M; ++i) {
        each_pebble_prob = 1.0;
        if (pebble[i] >= K) {
            for (int j = 0; j < K; ++j)
                each_pebble_prob *= (pebble[i] - j) / double(N - j);
            all_pebble_prob += each_pebble_prob;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> pebble[i];
        N += pebble[i];
    }
    cin >> K;

    calculate();

    cout << setprecision(9) << all_pebble_prob;

    return 0;
}