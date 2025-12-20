#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> v;
int si, sj;
int ansMAP[1003][1003];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

queue<pair<int, int>> q;
bool visited[1003][1003];

void fc(int y, int x) {
    ansMAP[y][x] = 0;
    visited[y][x] = true;

    q.push({y, x});

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                continue;
            }
            if (visited[ny][nx]) {
                continue;
            }
            if (v[ny][nx] == 0) {
                continue;
            }

            ansMAP[ny][nx] = ansMAP[cy][cx] + 1;
            visited[ny][nx] = true;
            q.push({ny, nx});

//            if (!visited[ny][nx] && ny >= 0 && ny < n && nx >= 0 && nx < m) {
//                if (v[ny][nx] != 0) {
//                    ansMAP[ny][nx] = ansMAP[cy][cx] + 1;
//                    visited[ny][nx] = true;
//                    q.push({ny, nx});
//                }
//            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && v[i][j] == 1) {
                ansMAP[i][j] = -1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    v.resize(n + 1);
    for (int i = 0; i < n + 1; i++) {
        v[i].resize(m + 1, 0);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];

            if (v[i][j] == 2) {
                si = i;
                sj = j;
            }
        }
    }

    fc(si, sj);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ansMAP[i][j] << " ";
        }
        cout << '\n';
    }
}