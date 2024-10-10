#include <iostream>
#include <queue>

using namespace std;

int n, m;
int maxArea;
int MAP[503][503];
int visited[503][503];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int a, int b) {
    int area = 0;
    if (visited[a][b] == 0) {
        visited[a][b] = 1;
        area++;
    }

    queue<pair<int,int>> q;
    q.push({a, b});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny] == 0 && MAP[nx][ny] == 1) {
                visited[nx][ny] = 1;
                area++;
                q.push({nx, ny});
            }
        }
    }

    if (area >= maxArea) maxArea = area;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> MAP[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (MAP[i][j] == 1 && visited[i][j] == 0) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << " " << maxArea;
    return 0;
}