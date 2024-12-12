#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
char MAP[51][51];
bool row[51];
bool col[51];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> MAP[i][j];
            if (MAP[i][j] == 'X') {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    int ans = 0;
    int checkRow = 0;
    int checkCol = 0;

    for (int i = 0; i < N; i++) {
        if (!row[i]) {
            checkRow++;
        }
    }

    for (int j = 0; j < M; j++) {
        if (!col[j]) {
            checkCol++;
        }
    }

    ans = max(checkRow, checkCol);
    cout << ans;
    return 0;
}