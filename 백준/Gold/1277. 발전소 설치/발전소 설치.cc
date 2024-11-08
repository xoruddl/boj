#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N, W;
int x[1001], y[1001], visited[1001], P[1001][1001];
double M, d[1001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> W >> M;

    for (int i = 1; i <= N; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            P[i][j] = 1;
        }
    }

    for (int i = 0; i < W; i++) {
        int a, b;
        cin >> a >> b;
        P[a][b] = 0;
        P[b][a] = 0;
    }

    d[1] = 0;
    for (int i = 2; i <= N; i++) {
        d[i] = 300000;
    }

    int cur = 1;
    while (1) {
        for (int i = 2; i <= N; i++) {
            // 초기에 미연결이면 거리 구함, 연결상태이면 그냥 거리 0
            double dis = P[cur][i] ? sqrt(pow(x[cur] - x[i], 2) + pow(y[cur] - y[i], 2)) : 0;
            // 미방문한 곳이고 잇는게 가능한 거리면 가장 최소 길이로 저장함
            if (!visited[i] && dis <= M) {
                d[i] = min(d[i], d[cur] + dis);
            }
        }
        visited[cur] = true;

        double m = 300000;
        for (int i = 2; i <= N; i++) {
            if (!visited[i] && d[i] < m) {
                m = d[i];
                cur = i;
            }
        }
        if (m == 300000) break;
    }
    cout << int(1000 * d[N]);
}