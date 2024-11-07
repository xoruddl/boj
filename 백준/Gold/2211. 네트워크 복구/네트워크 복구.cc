#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int Dist[1003];
int parent[1003];
vector<pair<int,  int>> v[1003];

void fc(int start) {
    for (int i = 1; i <= N; i++) Dist[i] = 2e9;
    Dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int ncost = v[cur][i].second;

            if (Dist[next] > cost + ncost) {
                Dist[next] = cost + ncost;
                parent[next] = cur;
                pq.push({-Dist[next], next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    fc(1);
    cout << N - 1 << '\n';
    for (int i = 2; i <= N; i++) {
        cout << parent[i] << " " << i << '\n';
    }
}