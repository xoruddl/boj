#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9
using namespace std;

int N, M;
int dp[103][103];
int path[103][103];
vector<int> v;

void Floyd() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) continue;
                if (dp[i][j] > dp[i][k] + dp[k][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}

void findPath(int s, int e) {
    if (path[s][e] == 0) {
        v.push_back(s);
        v.push_back(e);
        return;
    }
    findPath(s, path[s][e]);
    v.pop_back();
    findPath(path[s][e], e);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = INF;
        }
    }
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], c);
    }

    Floyd();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dp[i][j] == INF) cout << 0 << ' ';
            else cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dp[i][j] == INF) cout << 0;
            else {
                v.clear();
                findPath(i, j);
                cout << v.size() << ' ';
                for (int k = 0; k < v.size(); k++) {
                    cout << v[k] << ' ';
                }
            }
            cout << '\n';
        }
    }
    return 0;
}