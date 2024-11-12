#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int MAP[2225][2225];
int dp[2225][2225];
int dx[] = {1, 0};
int dy[] = {0, 1};

void fc() {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {1, 1}});

    while (!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int cost = pq.top().first;
        pq.pop();

        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ncost = cost;

            if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
            if (MAP[nx][ny] >= MAP[x][y]) {
                ncost += (MAP[nx][ny] - MAP[x][y] + 1);
            }
            if (ncost >= dp[nx][ny]) {
                continue;
            }
            dp[nx][ny] = ncost;
            pq.push({ncost, {nx, ny}});
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> MAP[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = 2e9;
        }
    }
    dp[1][1] = 0;

    fc();
    cout << dp[n][n];
}