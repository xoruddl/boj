#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string s1, s2;
vector<char> ans;
int dp[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s1 >> s2;

    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[s1.size()][s2.size()] << '\n';

    int i = s1.size();
    int j = s2.size();
    while (i != 0 && j != 0) {
        if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else if (dp[i][j] == dp[i][j - 1]) {
            j--;
        } else {
            ans.push_back(s1[i - 1]);
            i--;
            j--;
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
    return 0;
}