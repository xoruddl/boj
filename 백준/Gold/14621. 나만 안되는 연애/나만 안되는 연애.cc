#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, p[1001];
char MW[1001];
vector<pair<pair<int, int>, int>> edge;

int find(int x) {
    if (p[x] == x) return x;
    else return p[x] = find(p[x]);
}

void uni(int x, int y) {
    x = find(x);
    y = find(y);
    p[y] = x;
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
        p[i] = i;   // 부모 베열 초기화
        cin >> MW[i];   // 학교 입력
    }

    for (int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        if (MW[u] != MW[v]) {
            edge.push_back({{u, v}, d});
        }
    }

    sort(edge.begin(), edge.end(), cmp);    // 최소비용으로 정렬
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Input();

    int ans = 0, cnt = 0;
    for (auto V: edge) {
        int u = V.first.first;
        int v = V.first.second;
        int d = V.second;

        if (!sameParent(u, v)) {    // 연결되어있지 않다면
            uni(u, v);
            ans += d;
            cnt++;
            if (cnt == N - 1) { // 다 연결되었다면
                cout << ans;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}