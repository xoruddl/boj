#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int a, b, c;
int s, t;
vector<pair<int, int>> v[5003];
int dist[5003];

void fc(int start) {
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int cost = v[cur][i].second;

            if (dist[next] > dist[cur] + cost) {
                dist[next] = dist[cur] + cost;
                pq.push({cost, next});
            }
        }
    }
    cout << dist[t];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    cin >> s >> t;

    for (int i = 0; i < 5001; i++) {
        dist[i] = 2e9;
    }

    fc(s);
}
