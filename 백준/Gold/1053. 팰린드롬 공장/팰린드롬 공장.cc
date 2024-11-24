#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string s;
int ans;
int dp[50][50];

int solve(int left, int right) {
    if (dp[left][right] != -1) return dp[left][right];
    if (left >= right) return 0;
    dp[left][right] = min({solve(left + 1, right) + 1, solve(left, right - 1) + 1,
                           solve(left + 1, right - 1) + (s[left] != s[right])});
    return dp[left][right];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;
    memset(dp, -1, sizeof(dp));
    ans = solve(0, s.size() - 1);

    for (int i = 0; i < s.size() - 1; i++) {
        for (int j = i + 1; j < s.size(); j++) {
            memset(dp, -1, sizeof(dp));
            swap(s[i], s[j]);
            ans = min(ans, solve(0, s.size() - 1) + 1);
            swap(s[i], s[j]);
        }
    }
    cout << ans;
    return 0;
}