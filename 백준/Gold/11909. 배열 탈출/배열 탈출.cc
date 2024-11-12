#include <iostream>
#include <algorithm>

using namespace std;

int n;
int MAP[2225][2225];
int dp[2225][2225];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> MAP[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 2e9;
        }
    }

    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j]
            + max(MAP[i][j] - MAP[i - 1][j] + 1, 0));
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1]
                                                + max(MAP[i][j] - MAP[i][j - 1] + 1, 0));
        }
    }
    cout << dp[n - 1][n - 1];
}