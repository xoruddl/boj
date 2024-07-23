#include <iostream>
#include <queue>

using namespace std;

int N, M;
char MAP[12][12];
bool visited[12][12][12][12];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct step {
    int Rx, Ry;
    int Bx, By;
    int count;
};

void move(int& rx, int& ry, int& dist, int& i) {
    while (MAP[rx + dx[i]][ry + dy[i]] != '#' && MAP[rx][ry] != 'O') {
        rx += dx[i];
        ry += dy[i];
        dist += 1;
    }
}

void bfs(int Rx, int Ry, int Bx, int By) {
    queue<step> q;
    q.push({Rx, Ry, Bx, By, 0});
    visited[Rx][Ry][Bx][By] = true;
    while (!q.empty()) {
        int rx = q.front().Rx;
        int ry = q.front().Ry;
        int bx = q.front().Bx;
        int by = q.front().By;
        int count = q.front().count;
        q.pop();

        if (count >= 10) break;

        for (int i = 0; i < 4; i++) {
            int nrx = rx, nry = ry, nbx = bx, nby = by;
            int rc = 0, bc = 0, ncount = count + 1;
            move(nrx, nry, rc, i);
            move(nbx, nby, bc, i);

            if (MAP[nbx][nby] == 'O') continue;
            if (MAP[nrx][nry] == 'O') {
                cout << ncount;
                return;
            }
            if (nrx == nbx && nry == nby) {
                if (rc > bc) nrx -= dx[i], nry -= dy[i];
                else nbx -= dx[i], nby -= dy[i];
            }
            if (visited[nrx][nry][nbx][nby]) continue;
            visited[nrx][nry][nbx][nby] = true;
            q.push({nrx, nry, nbx, nby, ncount});
        }
    }
    cout << -1;
}

void solve() {
    cin >> N >> M;
    int Rx, Ry, Bx, By;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> MAP[i][j];
            if (MAP[i][j] == 'R') Rx = i, Ry = j;
            else if (MAP[i][j] == 'B') Bx = i, By = j;
        }
    }
    bfs(Rx, Ry, Bx, By);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}