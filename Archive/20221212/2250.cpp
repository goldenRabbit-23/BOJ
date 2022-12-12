#include <bits/stdc++.h>
using namespace std;

vector<int> tree[10001];
int parent[10001];
pair<int, int> level[10001];
int cnt = 0;
int maxDepth = 0;

void inorder(int u, int d) {
    maxDepth = max(maxDepth, d);
    if (tree[u][0] == -1 && tree[u][1] == -1) {
        if (level[d].first == 0)
            level[d].first = ++cnt;
        else
            level[d].second = ++cnt;
        return;
    }
    if (tree[u][0] != -1) inorder(tree[u][0], d + 1);
    if (level[d].first == 0)
        level[d].first = ++cnt;
    else
        level[d].second = ++cnt;
    if (tree[u][1] != -1) inorder(tree[u][1], d + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N;
    int a, b, c;
    int ans_level = 0, ans_width = 0;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b >> c;
        tree[a].push_back(b);
        tree[a].push_back(c);
        parent[b] = parent[c] = a;
    }

    for (int i = 1; i <= N; ++i) {
        if (!parent[i]) {
            inorder(i, 1);
            break;
        }
    }

    for (int i = 1; i <= maxDepth; ++i) {
        if (level[i].second == 0) {
            if (ans_width < 1) {
                ans_level = i;
                ans_width = 1;
            }
        } else {
            if (ans_width < level[i].second - level[i].first + 1) {
                ans_level = i;
                ans_width = level[i].second - level[i].first + 1;
            }
        }
    }

    cout << ans_level << ' ' << ans_width;

    return 0;
}