#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> v;
int dp[10003];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = v[i]; j <= k; j++) {
            dp[j] += dp[j - v[i]];
        }
    }
    cout << dp[k];
}