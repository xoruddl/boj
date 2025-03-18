#include <iostream>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

int H, W;
char MAP[503][503];
int dist[503][503];

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int targetX = 0;
int targetY = 0;

void bfs(int b, int a) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0,{b, a}});
    dist[b][a] = 0;

    while (!pq.empty()) {
        int d = pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();

        if (d > dist[y][x]) {
            continue;
        }

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nDist = d + (dx[i] != 1);

            if ((nx < 0 || nx >= W || ny < 0 || ny >= H) || MAP[ny][nx] == '#') continue;

            if (dist[ny][nx] > nDist) {
                dist[ny][nx] = nDist;
                pq.push({nDist, {ny, nx}});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int x, y;

    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> MAP[i][j];
            if (MAP[i][j] == 'K') {
                x = j;
                y = i;
            }
            if (MAP[i][j] == '*') {
                targetX = j;
                targetY = i;
            }
        }
    }

    for (int i = 0; i < 503; i++) {
        for (int j = 0; j < 503; j++) {
            dist[i][j] = INF;
        }
    }

//    for (int i = 0; i < H; i++) {
//        for (int j = 0; j < W; j++) {
//            cout << dist[i][j];
//        }
//        cout << '\n';
//    }
    bfs(y, x);

    if (dist[targetY][targetX] == INF) {
        cout << -1;
    }
    else {
        cout << dist[targetY][targetX];
    }
}
