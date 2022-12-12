#include <bits/stdc++.h>
using namespace std;

int ally[2001];
int enemy[2001];
int member[2001];

int find_root(int u) {
    if (ally[u] == u)
        return u;
    return ally[u] = find_root(ally[u]);
}

void union_root(int u, int v) {
    int p = find_root(u);
    int q = find_root(v);

    if (member[p] < member[q]) {
        ally[p] = q;
        member[q] += member[p];
    } else {
        ally[q] = p;
        member[p] += member[q];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, A, B;
    bool valid = 1;

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        ally[i] = i;
        member[i] = 1;
    }

    for (int i = 0; i < M; ++i) {
        cin >> A >> B;
        int x = find_root(A);
        int y = find_root(B);

        if (x == y) {
            valid = 0;
            break;
        }

        if (enemy[x])
            union_root(enemy[x], y);
        else
            enemy[x] = y;

        if (enemy[y])
            union_root(enemy[y], x);
        else
            enemy[y] = x;
    }

    cout << valid;

    return 0;
}