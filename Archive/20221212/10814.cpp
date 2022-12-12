#include <bits/stdc++.h>
using namespace std;

struct compare {
    bool operator()(const pair<int, int>& left,
                    const pair<int, int>& right) const {
        if (left.first == right.first)
            return left.second < right.second;
        else
            return left.first < right.first;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    int age;
    string name;
    map<pair<int, int>, string, compare> list;
    map<int, int> ageCount;

    cin >> N;
    while (N--) {
        cin >> age >> name;
        ++ageCount[age];
        list.emplace(make_pair(age, ageCount[age]), name);
    }

    for (auto it = list.begin(); it != list.end(); ++it)
        cout << it->first.first << ' ' << it->second << '\n';

    return 0;
}