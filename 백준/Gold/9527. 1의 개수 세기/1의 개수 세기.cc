#include <iostream>
using namespace std;

typedef long long ll;

ll dp[55];
ll A, B;

ll fc(ll x) {
    ll ans = x & 1;
    for (int i = 55; i > 0; i--) {
        if (x & (1LL<<i)) {
            ans += dp[i - 1] + (x - (1LL<<i) + 1);
            x -= (1LL << i);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> A >> B;

    dp[0] = 1;
    for (int i = 1; i < 55; i++) {
        dp[i] = 2 * dp[i - 1] + (1LL<<i);
    }

    cout << fc(B) - fc(A - 1);
}