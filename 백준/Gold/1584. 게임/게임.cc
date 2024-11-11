#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int MAP[503][503];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int N, M;
bool visited[503][503];

struct Point {
    int x;
    int y;
    int damage;
};

void fc() {
    deque<Point> dq;
    dq.push_back({0, 0, 0});

    while (!dq.empty()) {
        Point temp = dq.front();
        int x = temp.x;
        int y = temp.y;
        int dmg = temp.damage;

        if (x == 500 && y == 500) {
            cout << dmg;
            return;
        }
        dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ndmg = dmg;
            if (nx < 0 || nx > 500 || ny < 0 || ny > 500) {
                continue;
            }
            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                if (MAP[nx][ny] == 0) {
                    dq.push_front({nx, ny, ndmg});
                }
                else if (MAP[nx][ny] == 1){
                    dq.push_back({nx, ny, ndmg + 1});
                }
            }
        }
    }
    cout << -1;
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // 위험지역 만들기
        for (int j = min(x1, x2); j <= max(x1, x2); j++) {
            for (int k = min(y1, y2); k <= max(y1, y2); k++) {
                MAP[j][k] = 1;
            }
        }
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // 죽음지역 만들기
        for (int j = min(x1, x2); j <= max(x1, x2); j++) {
            for (int k = min(y1, y2); k <= max(y1, y2); k++) {
                MAP[j][k] = 2;
            }
        }
    }

    fc();
    return 0;
}
