#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
vector<int> v;
int dp[100003];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    fill(dp, dp + 100003, 2e9);

    dp[0] = 0;

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < v.size(); j++) {
            if (i < v[j]) continue;
            dp[i] = min(dp[i], dp[i - v[j]] + 1);
        }

    }
    if (dp[k] == 2e9) {
        cout << -1;
    }
    else {
        cout << dp[k];
    }
}