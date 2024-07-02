#include <iostream>

using namespace std;

int N, M, ans;
int MAP[501][501];
int DP[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int DFS(int x, int y) {
    if (x == M - 1 && y == N - 1) return 1;
    if (DP[x][y] != -1) return DP[x][y];

    DP[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
            if (MAP[nx][ny] < MAP[x][y]) {
                DP[x][y] = DP[x][y] + DFS(nx, ny);
            }
        }
    }
    return DP[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> MAP[i][j];
            DP[i][j] = -1;
        }
    }

    ans = DFS(0, 0);
    cout << ans << '\n';
    return 0;
}