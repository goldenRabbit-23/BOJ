#include <algorithm>
#include <array>
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

    string str;
    bool found = false;

    auto convert = [](int x) -> string {
        if (x % 3 == 0 && x % 5 == 0)
            return "FizzBuzz";
        else if (x % 3 == 0)
            return "Fizz";
        else if (x % 5 == 0)
            return "Buzz";
        else
            return to_string(x);
    };

    for (int i = 0; i < 3; i++) {
        cin >> str;

        if (!found && '0' <= str[0] && str[0] <= '9') {
            cout << convert(stoi(str) + 3 - i) << '\n';
            found = true;
        }
    }

    return 0;
}