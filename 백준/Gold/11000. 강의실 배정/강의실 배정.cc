#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, ans;
int s, t;
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s >> t;
        v.push_back({s, t});
    }
    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(v[0].second);
    for (int i = 1; i < v.size(); i++) {
        if (v[i].first >= pq.top()) {
            pq.pop();
            pq.push(v[i].second);
        }
        else {
            pq.push(v[i].second);
        }
    }

    cout << pq.size() << '\n';
    return 0;
}