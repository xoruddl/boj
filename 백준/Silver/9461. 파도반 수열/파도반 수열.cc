#include <iostream>

using namespace std;

typedef long long ll;

int T;
ll dp[103];

void makeDP() {
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    for (int i = 6; i <= 100; i++) {
        dp[i] = dp[i -1] + dp[i - 5];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    makeDP();

    while(T--) {
        int N;
        cin >> N;
        cout << dp[N] << '\n';
    }
}