#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    string com;
    int n, t;
    vector<pair<int, int>> memo;

    while (N-- > 0) {
        cin >> com;

        if (com == "order") {
            cin >> n >> t;
            memo.emplace_back(n, t);
        } else if (com == "sort") {
            sort(memo.begin(), memo.end(), [](auto &p, auto &q) -> bool {
                if (p.second == q.second)
                    return p.first < q.first;
                return p.second < q.second;
            });
        } else if (com == "complete") {
            cin >> n;
            memo.erase(find_if(memo.begin(), memo.end(), [n](auto &p) -> bool {
                return p.first == n;
            }));
        }

        if (!memo.empty()) {
            for (int i = 0; i < int(memo.size()); i++)
                cout << memo[i].first << ' ';
            cout << '\n';
        } else {
            cout << "sleep" << '\n';
        }
    }

    return 0;
}