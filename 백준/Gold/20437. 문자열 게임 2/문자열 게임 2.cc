#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, K;
string W;
vector<int> v[26];

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> W;
        cin >> K;

        int mini = 2e9;
        int maxi = 0;
        for (int i = 0; i < 26; i++) v[i].clear();
        for (int i = 0; i < W.size(); i++) {
            int num = W[i] - 97;
            v[num].push_back(i);
        }

        for (int i = 0; i < 26; i++) {
            int vsize = v[i].size();
            if (vsize >= K) {
                for (int j = 0; j <= vsize - K; j++) {
                    mini = min(mini, v[i][j + K - 1] - v[i][j] + 1);
                    maxi = max(maxi, v[i][j + K - 1] - v[i][j] + 1);
                }
            }
        }

        if (mini == 2e9 || maxi == 0) cout << -1 << '\n';
        else cout << mini << " " << maxi << '\n';
    }
    return 0;
}