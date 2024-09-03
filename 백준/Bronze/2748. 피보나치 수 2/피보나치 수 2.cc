#include <iostream>

using namespace std;

int N;
long long dp[93];

int main() {
    dp[0] = 0;
    dp[1] = 1;

    cin >> N;
    for (int i = 2; i <= 90; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[N];
    return 0;
}
