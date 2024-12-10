#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, pair<int, int>>> v;

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    return a.first > b.first;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b, score;
        cin >> a >> b >> score;
        v.push_back({score, {a, b}});
    }

    sort(v.begin(), v.end(), cmp);

    cout << v[0].second.first << " " << v[0].second.second << '\n';
    cout << v[1].second.first << " " << v[1].second.second << '\n';

    int t = 0;
    if (v[0].second.first == v[1].second.first) {
        for (int i = 2; i < N; i++) {
            if (v[i].second.first == v[0].second.first) continue;
            else {
                t = i;
                break;
            }
        }
    }
    else {
        cout << v[2].second.first << " " << v[2].second.second << '\n';
        return 0;
    }
    cout << v[t].second.first << " " << v[t].second.second << '\n';
}
