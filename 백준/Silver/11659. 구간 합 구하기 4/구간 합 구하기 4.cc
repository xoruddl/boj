#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;
int dp[100003];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        v.push_back(a);

        dp[i] = dp[i - 1] + a;
    }


    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;

        cout << dp[e] - dp[s - 1] << '\n';
    }
}
