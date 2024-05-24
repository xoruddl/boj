#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    dp[1] = -1;
    dp[2] = 1;
    dp[3] = -1;
    dp[4] = 2;
    dp[5] = 1;
    dp[6] = 3;
    dp[7] = 2;
    dp[8] = 4;
    dp[9] = 3;
    dp[10] = 2;

    for (int i = 11; i <= 100000; i++) {
        dp[i] = min(dp[i - 2] + 1, dp[i - 5] + 1);
    }
    cout << dp[n] << '\n';
    return 0;
}