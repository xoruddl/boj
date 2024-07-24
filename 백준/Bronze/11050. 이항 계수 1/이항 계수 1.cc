#include <iostream>

using namespace std;

int dp[20][20];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            if (j == 0 || j == i) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    cout << dp[N][K];
    return 0;
}