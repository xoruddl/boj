#include <iostream>
#include <algorithm>

using namespace std;

int N;
char boj[1003];
int dp[1003];

void solve() {
    dp[1] = 0;
    for (int i = 1; i <= N; i++) {
        if (boj[i] == 'B') {
            for (int j = i + 1; j <= N; j++) {
                if (boj[j] == 'O') {
                    dp[j] = min(dp[j], (j - i) * (j - i) + dp[i]);
                }
            }
        }
        else if (boj[i] == 'O') {
            for (int j = i + 1; j <= N; j++) {
                if (boj[j] == 'J') {
                    dp[j] = min(dp[j], (j - i) * (j - i) + dp[i]);
                }
            }
        }
        else {
            for (int j = i + 1; j <= N; j++) {
                if (boj[j] == 'B') {
                    dp[j] = min(dp[j], (j - i) * (j - i) + dp[i]);
                }
            }
        }
    }
    if (dp[N] == 2e9) {
        cout << -1;
    }
    else {
        cout << dp[N];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> boj[i];
    }

    fill(dp, dp + 1001, 2e9);
    solve();
}