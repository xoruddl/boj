#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C;
int ans;
vector<vector<int>> MAP;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool visited[27];

void dfs(int x, int y, int cnt) {
    ans = max(cnt, ans);

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= C || ny < 0 || ny >= R) {
            continue;
        }
        int next = MAP[ny][nx];
        if (!visited[next]) {
            visited[next] = true;
            dfs(nx, ny, cnt + 1);
            visited[next] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> R >> C;
    MAP.resize(R);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char c; cin >> c;
            MAP[i].push_back(c - 'A');
        }
    }

    visited[MAP[0][0]] = true;
    dfs(0, 0, 1);

    cout << ans;
}