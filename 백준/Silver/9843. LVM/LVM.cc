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
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<string, int>> instructions(N);

    for (auto &[inst, x] : instructions) {
        cin >> inst;
        if (inst == "PUSH" || inst == "IFZERO")
            cin >> x;
    }

    stack<int> st;
    int reg = 0;
    int cur_inst = 0;

    while (true) {
        auto &[inst, x] = instructions[cur_inst];

        if (inst == "PUSH") {
            st.push(x);
        } else if (inst == "STORE") {
            reg = st.top(); st.pop();
        } else if (inst == "LOAD") {
            st.push(reg);
        } else if (inst == "PLUS") {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            st.push(a + b);
        } else if (inst == "TIMES") {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            st.push(a * b);
        } else if (inst == "IFZERO") {
            int t = st.top(); st.pop();
            if (t == 0) {
                cur_inst = x;
                continue;
            }
        } else if (inst == "DONE") {
            cout << st.top() << '\n';
            break;
        }

        cur_inst++;
    }

    return 0;
}