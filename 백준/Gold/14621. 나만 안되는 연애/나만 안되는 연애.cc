#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int parent[1001];
char MW[1001];
vector<pair<pair<int, int>, int>> Edge;

int find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void uni(int x, int y) {
    x = find(x);
    y = find(y);
    parent[y] = x;
}

bool sameParent(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return true;
    else return false;
}

bool cmp(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2) {
    return p1.second < p2.second;
}

void Input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        cin >> MW[i];
    }

    for (int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        if (MW[u] != MW[v]) {
            Edge.push_back({{u, v}, d});
        }
    }
    sort(Edge.begin(), Edge.end(), cmp);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Input();

    int ans = 0, cnt = 0;
    for (auto E: Edge) {
        int u = E.first.first;
        int v = E.first.second;
        int d = E.second;

        if (!sameParent(u, v)) {
            ans += d;
            uni(u, v);
            cnt++;
            if (cnt == N - 1) {
                cout << ans;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}