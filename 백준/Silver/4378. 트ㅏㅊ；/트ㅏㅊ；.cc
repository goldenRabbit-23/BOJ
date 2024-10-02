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

map<char, char> keyboard = {
    {'1', '`'}, {'2', '1'}, {'3', '2'}, {'4', '3'}, {'5', '4'}, {'6', '5'}, {'7', '6'}, {'8', '7'}, {'9', '8'}, {'0', '9'}, {'-', '0'}, {'=', '-'},
    {'W', 'Q'}, {'E', 'W'}, {'R', 'E'}, {'T', 'R'}, {'Y', 'T'}, {'U', 'Y'}, {'I', 'U'}, {'O', 'I'}, {'P', 'O'}, {'[', 'P'}, {']', '['}, {'\\', ']'},
    {'S', 'A'}, {'D', 'S'}, {'F', 'D'}, {'G', 'F'}, {'H', 'G'}, {'J', 'H'}, {'K', 'J'}, {'L', 'K'}, {';', 'L'}, {'\'', ';'},
    {'X', 'Z'}, {'C', 'X'}, {'V', 'C'}, {'B', 'V'}, {'N', 'B'}, {'M', 'N'}, {',', 'M'}, {'.', ','}, {'/', '.'},
    {' ', ' '}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;

    while (getline(cin, line)) {
        for (auto &c : line)
            cout << keyboard[c];
        cout << '\n';
    }

    return 0;
}