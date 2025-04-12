#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
int dp[503][503];
int m[503];
int P[503][503];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        m[i - 1] = a;
        m[i] = b;
    }

    for (int diagonal = 1; diagonal <= N - 1; diagonal++) {
        for (int i = 1; i <= N - diagonal; i++) {
            int j = i + diagonal;
            dp[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + m[i - 1] * m[k] * m[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    P[i][j] = k;
                }
            }
        }
    }

    cout << dp[1][N];
}