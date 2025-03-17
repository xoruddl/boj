#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>

#define MOD 10

using namespace std;

int MAP[1003][1003];
int N, M;
int newMAP[1003][1003];
int areaNum[1003][1003];    // 0이 있는 구역 나누기
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool visited[1003][1003];
int cnt;
vector<int> zeroAreaSize;   // 각 0의 구역의 사이즈

void bfs(int b, int a) {
    int val = 1;
    areaNum[b][a] = cnt;
    visited[b][a] = true;

    queue<pair<int, int>> q;
    q.push({b, a});

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                if (MAP[ny][nx] == 0 && !visited[ny][nx]) {
                    visited[ny][nx] = true;
                    areaNum[ny][nx] = cnt;
                    q.push({ny, nx});
                    val++;
                }
            }
        }
    }
    zeroAreaSize.push_back(val);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++) {
            MAP[i][j] = line[j] - '0';
        }
    }
    memset(areaNum, -1, sizeof(areaNum));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (MAP[i][j] == 0 && !visited[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (MAP[i][j] == 1) {
                set<int> search;
                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
                        if (MAP[ny][nx] == 0) {
                            if (search.find(areaNum[ny][nx]) == search.end()) {
                                search.insert(areaNum[ny][nx]);
                                newMAP[i][j] += zeroAreaSize[areaNum[ny][nx]];
                            }
                        }
                    }
                }
                newMAP[i][j]++;
                newMAP[i][j] %= MOD;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << newMAP[i][j];
        }
        cout << '\n';
    }
    return 0;
}
