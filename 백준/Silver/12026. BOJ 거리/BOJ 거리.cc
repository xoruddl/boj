#include <iostream>
#include <algorithm>

using namespace std;

int N;
char street[1001];
int dp[1010];

void solve() {
    dp[1] = 0;
    for (int i = 1; i < N; i++) {
        if (street[i] == 'B') {
            for (int j = i + 1; j <= N; j++) {
                if (street[j] == 'O') {
                    dp[j] = min(dp[j], (j - i) * (j - i) + dp[i]);
                }
            }
        }
        else if (street[i] == 'O') {
            for (int j = i + 1; j <= N; j++) {
                if (street[j] == 'J') {
                    dp[j] = min(dp[j], (j - i) * (j - i) + dp[i]);
                }
            }
        }
        else {
            for (int j = i + 1; j <= N; j++) {
                if (street[j] == 'B') {
                    dp[j] = min(dp[j], (j - i) * (j - i) + dp[i]);
                }
            }
        }
    }

    if (dp[N] == 2e9) {
        cout << -1 << '\n';
    }
    else {
        cout << dp[N] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> street[i];
    }
    fill(dp, dp + 1001, 2e9);
    solve();
    return 0;
}