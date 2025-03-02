#include <iostream>

#define MOD 1000000000
#define ll long long

using namespace std;

int N;
ll dp[1<<10][101][10];
// dp[bit][i][k] : 길이가 i이고, 마지막 숫자가 k, 사용된 숫자가 bit인 경우의 수를 나타내는 배열

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    if (N <= 9) {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 1; i <= 9; i++) {
        dp[1<<i][1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {  // i는 숫자 개수
        for (int k = 0; k <= 9; k++) {  // k는 마지막 숫자 번호
            for (int bit = 0; bit < (1<<10); bit++) {   // bit는 이전비트
                if (k == 0) {
                    dp[bit | (1<<k)][i][k] += dp[bit][i - 1][k + 1] % MOD;
                }
                else if (k == 9) {
                    dp[bit | (1<<k)][i][k] += dp[bit][i - 1][k - 1] % MOD;
                }
                else {
                    dp[bit | (1<<k)][i][k] += (dp[bit][i - 1][k + 1] + dp[bit][i - 1][k - 1]) % MOD;
                }
            }
        }
    }
    
    ll ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans = (ans + dp[(1<<10) - 1][N][i]) % MOD;
    }
    cout << ans << '\n';
    return 0;
}