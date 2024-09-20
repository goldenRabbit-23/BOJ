#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, K;
    char com;
    int com2;
    priority_queue<int, vector<int>, less<int>> maxPQ;
    priority_queue<int, vector<int>, greater<int>> minPQ;
    map<int, int> m;

    cin >> T;
    while (T--) {
        while (!maxPQ.empty()) maxPQ.pop();
        while (!minPQ.empty()) minPQ.pop();
        m.clear();

        cin >> K;
        while (K--) {
            cin >> com;
            if (com == 'D') {
                cin >> com2;
                if (com2 == 1) {
                    while (!maxPQ.empty() && m[maxPQ.top()] == 0) maxPQ.pop();
                    if (!maxPQ.empty()) {
                        --m[maxPQ.top()];
                        maxPQ.pop();
                    }
                } else {
                    while (!minPQ.empty() && m[minPQ.top()] == 0) minPQ.pop();
                    if (!minPQ.empty()) {
                        --m[minPQ.top()];
                        minPQ.pop();
                    }
                }
            } else {
                cin >> com2;
                maxPQ.emplace(com2);
                minPQ.emplace(com2);
                ++m[com2];
            }
        }
        while (!maxPQ.empty() && m[maxPQ.top()] == 0) maxPQ.pop();
        while (!minPQ.empty() && m[minPQ.top()] == 0) minPQ.pop();

        if (maxPQ.empty())
            cout << "EMPTY\n";
        else
            cout << maxPQ.top() << ' ' << minPQ.top() << '\n';
    }

    return 0;
}