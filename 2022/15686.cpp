#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
bool selected[13];
int min_city_chicken_dist = int(1e9);
int house_cnt = 0, chicken_cnt = 0;

void calculate_distance() {
    int min_house_chicken_dist;
    int cur_house_chicken_dist;
    int cur_city_chicken_dist = 0;

    for (int i = 0; i < house_cnt; ++i) {
        min_house_chicken_dist = int(1e9);

        for (int j = 0; j < chicken_cnt; ++j) {
            if (selected[j]) {
                cur_house_chicken_dist =
                    abs(house[i].first - chicken[j].first) +
                    abs(house[i].second - chicken[j].second);

                if (min_house_chicken_dist > cur_house_chicken_dist)
                    min_house_chicken_dist = cur_house_chicken_dist;
            }
        }

        cur_city_chicken_dist += min_house_chicken_dist;
    }

    if (min_city_chicken_dist > cur_city_chicken_dist)
        min_city_chicken_dist = cur_city_chicken_dist;
}

void select_chicken() {
    do {
        calculate_distance();
    } while (next_permutation(selected, selected + chicken_cnt));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int city;

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> city;
            if (city == 1) {
                house.push_back({i, j});
                ++house_cnt;
            } else if (city == 2) {
                chicken.push_back({i, j});
                ++chicken_cnt;
            }
        }
    }

    for (int i = chicken_cnt - M; i < chicken_cnt; ++i) selected[i] = 1;

    select_chicken();

    cout << min_city_chicken_dist;

    return 0;
}