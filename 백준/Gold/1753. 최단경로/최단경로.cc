#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int V, E, K;
int dist[20003];
vector<pair<int, int>> vertex[20003];

void fc(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < vertex[cur].size(); i++) {
            int next = vertex[cur][i].first;
            int ncost = vertex[cur][i].second;

            if (dist[next] > cost + ncost) {
                dist[next] = cost + ncost;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> V >> E >> K;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vertex[u].push_back({v, w});
    }
    for (int i = 0; i <= V; i++) {
        dist[i] = INF;
    }

    fc(K);

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
}
