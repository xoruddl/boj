#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> v;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    int ans = 0;
    sort(v.begin(), v.end(), cmp);

    int temp = 0;
    for (auto a: v) {
        if (a.first >= temp) {
            ans++;
            temp = a.second;
        }
    }
    cout << ans;
}