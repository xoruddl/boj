#include <iostream>

using namespace std;

long long N, K, M;
int dp[2001][2001];  // 조합

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K >> M;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % M;
            }
        }
    }

    int ans = 1;
    while (N > 0 || K > 0) {
        int r1 = N % M;
        int r2 = K % M;
        N /= M;
        K /= M;

        ans = (ans * dp[r1][r2]) % M;
    }
    cout << ans << '\n';
    return 0;
}
