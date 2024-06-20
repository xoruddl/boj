#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, cnt;
string arr[26];
bool visited[26][26] = {0,};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> result;
queue<pair<int, int>> q;

void bfs(int x, int y) {
    q.push({x, y});
    visited[x][y] = true;
    cnt++;

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if (0 <= nx && 0 <= ny && nx < N && ny < N && visited[nx][ny] == false && arr[nx][ny] == '1') {
                q.push({nx, ny});
                visited[nx][ny] = true;
                cnt++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == '1' && visited[i][j] == false) {
                cnt = 0;
                bfs(i, j);
                result.push_back(cnt);
            }
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << '\n';
    for (auto a : result) {
        cout << a << '\n';
    }
}