#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, ans;
vector<vector<int>> MAP;

void move(int n) {
    queue<int> q;

    if (n == 0) {
        // left
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (MAP[i][j] != 0) {
                    q.push(MAP[i][j]);
                }
                MAP[i][j] = 0;
            }
            int idx = 1;

            while (!q.empty()) {
                int value = q.front();
                q.pop();

                if (MAP[i][idx] == 0) {
                    MAP[i][idx] = value;
                }
                else if (MAP[i][idx] == value) {
                    MAP[i][idx] *= 2;
                    idx++;
                }
                else {
                    idx++;
                    MAP[i][idx] = value;
                }
            }
        }
    }
    else if (n == 1) {
        //right
        for (int i = 1; i <= N; i++) {
            for (int j = N; j >= 1; j--) {
                if (MAP[i][j] != 0) {
                    q.push(MAP[i][j]);
                }
                MAP[i][j] = 0;
            }
            int idx = N;

            while (!q.empty()) {
                int value = q.front();
                q.pop();

                if (MAP[i][idx] == 0) {
                    MAP[i][idx] = value;
                }
                else if (MAP[i][idx] == value) {
                    MAP[i][idx] *= 2;
                    idx--;
                }
                else {
                    idx--;
                    MAP[i][idx] = value;
                }
            }
        }
    }
    else if (n == 2) {
        //up
        for (int j = 1; j <= N; j++) {
            for (int i = 1; i <= N; i++) {
                if (MAP[i][j] != 0) {
                    q.push(MAP[i][j]);
                }
                MAP[i][j] = 0;
            }
            int idx = 1;

            while (!q.empty()) {
                int value = q.front();
                q.pop();

                if (MAP[idx][j] == 0) {
                    MAP[idx][j] = value;
                }
                else if (MAP[idx][j] == value) {
                    MAP[idx][j] *= 2;
                    idx++;
                }
                else {
                    idx++;
                    MAP[idx][j] = value;
                }
            }
        }
    }
    else {
        //down
        for (int j = 1; j <= N; j++) {
            for (int i = N; i >= 1; i--) {
                if (MAP[i][j] != 0) {
                    q.push(MAP[i][j]);
                }
                MAP[i][j] = 0;
            }
            int idx = N;

            while (!q.empty()) {
                int value = q.front();
                q.pop();

                if (MAP[idx][j] == 0) {
                    MAP[idx][j] = value;
                }
                else if (MAP[idx][j] == value) {
                    MAP[idx][j] *= 2;
                    idx--;
                }
                else {
                    idx--;
                    MAP[idx][j] = value;
                }
            }
        }
    }
}

void dfs(int cnt) {
    if (cnt == 5) {
        return;
    }

    vector<vector<int>> newMAP;
    newMAP.resize(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            newMAP[i][j] = MAP[i][j];
        }
    }

    for (int m = 0; m < 4; m++) {
        move(m);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (MAP[i][j] > ans) {
                    ans = MAP[i][j];
                }
            }
        }

        dfs(cnt + 1);

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                MAP[i][j] = newMAP[i][j];
            }
        }
    }
}

int main() {

    cin >> N;
    MAP.resize(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> MAP[i][j];
        }
    }

    dfs(0);

    cout << ans;
}
