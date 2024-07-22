#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, ans;
int x_1, y_1, x_2, y_2;
bool ok = false;
char MAP[303][303];
bool visited[303][303];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int b, int a) {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({b, a});
    visited[b][a] = 1;

    while (!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (MAP[ny][nx] == '#') {
                ok = true;
                return;
            }
            if (ny >= 1 && ny <= N && nx >= 1 && nx <= M && !visited[ny][nx]) {
                visited[ny][nx] = 1;
                if (MAP[ny][nx] == '1') {
                    MAP[ny][nx] = '0';
                } else if (MAP[ny][nx] == '0') q.push({ny, nx});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    cin >> x_1 >> y_1 >> x_2 >> y_2;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> MAP[i][j];
        }
    }
    while (1) {
        ans++;
        bfs(x_1, y_1);
        if (ok) break;
    }
    cout << ans;
    return 0;
}