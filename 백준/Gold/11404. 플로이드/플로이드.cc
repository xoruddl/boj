#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;

int n, m;
int dp[103][103];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], c);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] == INF) {
                cout << 0 << ' ';
                continue;
            }
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}