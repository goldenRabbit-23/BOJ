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

    map<string, int> list;
    vector<string> duplicated;

    while (true) {
        string ssn;
        cin >> ssn;

        if (ssn == "000-00-0000")
            break;

        if (list[ssn] == 1)
            duplicated.push_back(ssn);

        list[ssn]++;
    }

    sort(duplicated.begin(), duplicated.end());

    for (auto &dup : duplicated)
        cout << dup << '\n';

    return 0;
}