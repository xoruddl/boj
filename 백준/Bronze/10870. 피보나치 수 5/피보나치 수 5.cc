#include <iostream>

using namespace std;

int n;
int dp[25];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= 20; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n] << '\n';
    return 0;
}