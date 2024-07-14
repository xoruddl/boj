#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int N, M, K;
vector<string> v;
map<string, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    cin >> K;

    for (auto a: v) {
        int zero = 0;
        for (auto b: a) {
            if (b == '0') zero++;
        }

        if (zero > K || (zero % 2 != K % 2)) continue;

        if (mp.find(a) == mp.end()) {
            mp.insert({a, 1});
        }
        else {
            mp[a]++;
        }
    }

    int ans = 0;
    for (auto a: mp) {
        ans = max(ans, a.second);
    }
    cout << ans;
    return 0;
}