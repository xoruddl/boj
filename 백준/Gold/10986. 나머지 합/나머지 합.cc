#include <iostream>
#include <vector>

using namespace std;

int N, M;
long long ans = 0;
vector<long long> dp, C;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    dp.push_back(0);
    C.resize(M + 1, 0);
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        int MOD = (dp[i - 1] + a) % M;
        if (MOD == 0) ans++;
        dp.push_back(MOD);

        C[MOD]++;
    }

    for (int i = 0; i < M; i++) {
        if (C[i] > 1) {
            ans += C[i] * (C[i] - 1) / 2 ;
        }
    }
    cout << ans;
}