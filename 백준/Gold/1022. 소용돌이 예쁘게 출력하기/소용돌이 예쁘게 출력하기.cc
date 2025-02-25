#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int r1, c1, r2, c2;
int map[51][5];

void makeMap() {
    int MAX = max(max(abs(r1), abs(c1)), max(abs(r2), abs(c2)));
    int val = 1;
    if (0 >= r1 && 0 >= c1 && 0 <= r2 && 0 <= c2)
        map[0 - r1][0 - c1] = val;

    int cnt = 0;
    int y = 0, x = 0;

    for (int i = 1; i <= MAX + 1; i++) {
        //오른쪽으로 이동
        for (int j = 1; j <= 1 + cnt * 2; j++) {
            val++;
            x++;
            if (y >= r1 && y <= r2 && x >= c1 && x <= c2) {
                map[y - r1][x - c1] = val;
            }
        }
        //위로 이동
        for (int j = 1; j <= 1 + cnt * 2; j++) {
            val++;
            y--;
            if (y >= r1 && y <= r2 && x >= c1 && x <= c2) {
                map[y - r1][x - c1] = val;
            }
        }
        //왼쪽으로 이동
        for (int j = 1; j <= 2 + cnt * 2; j++) {
            val++;
            x--;
            if (y >= r1 && y <= r2 && x >= c1 && x <= c2) {
                map[y - r1][x - c1] = val;
            }
        }
        //아래로 이동
        for (int j = 1; j <= 2 + cnt * 2; j++) {
            val++;
            y++;
            if (y >= r1 && y <= r2 && x >= c1 && x <= c2) {
                map[y - r1][x - c1] = val;
            }
        }

        cnt++;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> r1 >> c1 >> r2 >> c2;
    makeMap();

    int h = abs(r2 - r1);
    int w = abs(c2 - c1);

    // 맵 안의 최대값 뽑기
    int M = 0;
    for (int i = 0; i <= h; i++) {
        for (int j = 0;j <= w; j++) {
            M = max(M, map[i][j]);
        }
    }

    //최대 자리수 구하기
    int maxDegree = 0;
    for (int i = 1; i <= M; i *= 10) {
        maxDegree++;
    }

    for (int i = 0; i <= h; i++) {
        for (int j = 0; j <= w; j++) {
            int curDegree = 0;
            for (int k = 1; k <= map[i][j]; k *= 10) {
                curDegree++;
            }
            for (int k = curDegree; k < maxDegree; k++) {
                cout << " ";
            }

            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
}
