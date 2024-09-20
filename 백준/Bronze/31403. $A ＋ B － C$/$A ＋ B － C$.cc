#include <algorithm>
#include <array>
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

    int A, B, C;
    cin >> A >> B >> C;
    cout << A + B - C << '\n';

    int AB = stoi(to_string(A) + to_string(B));
    cout << AB - C << '\n';

    return 0;
}