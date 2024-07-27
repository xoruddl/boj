#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
int m[501][2];
int dp[501][501];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> m[i][0] >> m[i][1];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; i + j <= N; j++) {
            dp[j][i + j] = INT_MAX;
            for (int k = j; k <= i + j; k++) {
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + m[j][0] * m[k][1] * m[i + j][1]);
            }
        }
    }
    cout << dp[1][N];
    return 0;
}
