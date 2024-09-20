#include <iostream>
#include <vector>
using namespace std;

void run_case(int N) {
    vector<string> grid(N);

    for (auto &row : grid)
        cin >> row;

    int cnt;
    bool found;

    for (int r = 0; r < N; r++) {
        cnt = 0;
        found = false;

        for (int c = 0; c < N; c++) {
            if (grid[r][c] == '.') {
                if (cnt > 0) {
                    cout << cnt << ' ';
                    cnt = 0;
                }
                continue;
            }

            found = true;
            cnt++;
        }

        if (!found)
            cout << 0 << ' ';
        else if (cnt > 0)
            cout << cnt << ' ';

        cout << '\n';
    }

    for (int c = 0; c < N; c++) {
        cnt = 0;
        found = false;

        for (int r = 0; r < N; r++) {
            if (grid[r][c] == '.') {
                if (cnt > 0) {
                    cout << cnt << ' ';
                    cnt = 0;
                }
                continue;
            }

            found = true;
            cnt++;
        }

        if (!found)
            cout << 0 << ' ';
        else if (cnt > 0)
            cout << cnt << ' ';

        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;

    while (true) {
        cin >> N;
        if (N == 0)
            break;
        run_case(N);
    }

    return 0;
}