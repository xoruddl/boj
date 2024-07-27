#include <iostream>
#include <algorithm>

#define MAX 987654321

using namespace std;

int N;
int paint[1010][3];
int ans = MAX;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> paint[i][j];
        }
    }

    for (int start = 0; start < 3; ++start) {
        int dp[1001][3];
        for (int j = 0; j < 3; ++j) {
            if (j == start) dp[1][start] = paint[1][start];
            else dp[1][j] = MAX;
        }
        for (int i = 2; i <= N; ++i) {
            dp[i][0] = paint[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = paint[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = paint[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
        }
        for (int j = 0; j < 3; ++j) {
            if (j == start) continue;
            ans = min(ans, dp[N][j]);
        }
    }
    cout << ans;
    return 0;
}