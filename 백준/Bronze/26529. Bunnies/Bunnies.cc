#include <iostream>

using namespace std;

int n;
long long dp[48];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= 45; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    for (int t = 0; t < n; t++) {
        int a;
        cin >> a;
        cout << dp[a] << '\n';
    }
}
