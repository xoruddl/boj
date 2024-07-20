#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[22][302];
int dp[22][302];
int path[22][302];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int ii;
        cin >> ii;
        for (int j = 1; j <= M; j++) {
            cin >> arr[j][ii];
        }
    }

    for (int i = 1; i <= M; i++) {
        for (int cost = 1; cost <= N; cost++) {
            for (int j = 0; j <= cost; j++) {
                int val = dp[i - 1][cost - j] + arr[i][j];
                if (val > dp[i][cost]) {
                    dp[i][cost] = val;
                    path[i][cost] = j;
                }
            }
        }
    }

    cout << dp[M][N] << '\n';

    vector<int> ans;
    int curr = M;
    int cost = N;
    while (curr > 0) {
        int now_invest = path[curr][cost];
        ans.push_back(now_invest);

        cost -= now_invest;
        curr--;
    }

    reverse(ans.begin(), ans.end());
    for (auto it : ans) cout << it << ' ';
    return 0;
}
