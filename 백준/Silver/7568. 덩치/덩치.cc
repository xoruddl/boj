#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        v.push_back({x, y});
    }

    for (int i = 0; i < N; i++) {
        int ans = 1;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;

            if (v[i].first < v[j].first && v[i].second < v[j].second) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}