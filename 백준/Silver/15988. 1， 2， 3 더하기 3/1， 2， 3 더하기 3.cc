#include <iostream>

using namespace std;

int T;
long long dp[1000003];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;
    int n;
    while (T--) {
        cin >> n;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for (int i = 4; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
        }
        cout << dp[n] % 1000000009 << '\n';
    }
    
}