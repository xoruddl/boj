#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int N, K, L, ans;
vector<vector<int>> MAP;
queue<pair<int, char>> q;   //방향전환
deque<pair<int, int>> dq;   //뱀 좌표
int idx = 1;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void fc() {
    MAP[1][1] = 2e9;    //뱀 위치
    dq.push_back({1, 1});

    while (1) {
        ans++;
        int nx = dq.back().second + dx[idx];
        int ny = dq.back().first + dy[idx];
        if (nx <= 0 || nx > N || ny <= 0 || ny > N || MAP[ny][nx] == 2e9) {
            break;
        }

        //가는 곳에 사과 없는 경우
        if (MAP[ny][nx] != 1) {
            MAP[dq.front().first][dq.front().second] = 0;
            dq.pop_front();
        }
        MAP[ny][nx] = 2e9;
        dq.push_back({ny, nx});
        
        if (ans == q.front().first) {
            char c = q.front().second;
            if (c == 'D') {
                idx = (idx + 1) % 4;
            }
            else {
                idx = (idx - 1 + 4) % 4;
            }
            q.pop();
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    MAP.resize(N + 1, vector<int>(N + 1, 0));

    //사과위치
    for (int k = 0; k < K; k++) {
        int x, y;
        cin >> y >> x;
        MAP[y][x] = 1;
    }

    //방향전환
    cin >> L;
    for (int l = 0; l < L; l++) {
        int X;
        char C;
        cin >> X >> C;
        q.push({X, C});
    }

    fc();
    cout << ans;
}
