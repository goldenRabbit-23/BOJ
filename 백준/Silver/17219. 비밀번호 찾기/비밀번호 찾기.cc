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

    int N, M;
    cin >> N >> M;
    map<string, string> pwds;
    string site, pwd;

    for (int i = 0; i < N; i++) {
        cin >> site >> pwd;
        pwds[site] = pwd;
    }

    for (int i = 0; i < M; i++) {
        cin >> site;
        cout << pwds[site] << '\n';
    }

    return 0;
}