#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int MAP[301][301];
int temp[301][301];
bool visited[301][301];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, - 1};

void bfs(int a, int b) {
    queue<pair<int, int>> q;
    q.push({a, b});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (MAP[nx][ny] != 0 && !visited[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

void meltIce() {
    memset(temp, 0, sizeof(temp));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (MAP[i][j] == 0) continue;
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

                if (MAP[nx][ny] == 0) {
                    cnt++;
                }
            }
            int result = MAP[i][j] - cnt;
            if (result > 0) temp[i][j] = result;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            MAP[i][j] = temp[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> MAP[i][j];
        }
    }

    int time = 0;
    while (1) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (MAP[i][j] != 0 && !visited[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        if (cnt == 0) {
            cout << 0;
            break;
        }
        else if (cnt >= 2) {
            cout << time;
            break;
        }

        time++;
        meltIce();
        memset(visited, false, sizeof(visited));
    }
    return 0;
}