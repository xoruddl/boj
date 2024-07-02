#include <iostream>

using namespace std;

int N, M, ans;
int MAP[1025][1025];
int dp[1025][1025];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> MAP[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + MAP[i][j];
        }
    }

    int x1, y1, x2, y2;
    while (M--) {
        cin >> x1 >> y1 >> x2 >> y2;
        ans = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
        cout << ans << '\n';
    }
    return 0;
}