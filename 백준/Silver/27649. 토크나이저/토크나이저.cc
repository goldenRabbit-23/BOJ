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

array<char, 7> SPECIAL = {'<', '>', '&', '|', '(', ')', ' '};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    getline(cin, S);
    string token;

    auto is_token = [&](char c) -> bool {
        return find(SPECIAL.begin(), SPECIAL.end(), c) != SPECIAL.end();
    };

    for (int i = 0; i < int(S.size()); i++) {
        if (!is_token(S[i])) {  // normal character
            token += S[i];
        } else {  // special character
            if (token != "") {
                cout << token << ' ';
                token = "";
            }

            if (S[i] == '&' || S[i] == '|') {  // &, |
                cout << S[i] << S[i] << ' ';
                i++; // skip one
            } else if (S[i] != ' ') {  // <, >, (, )
                cout << S[i] << ' ';
            }

            // ignores whitespace
        }
    }

    cout << token << '\n';

    return 0;
}