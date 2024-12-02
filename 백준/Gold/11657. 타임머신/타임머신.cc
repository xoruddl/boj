#include <iostream>
#include <vector>

#define MAX 503
#define INF 2e9

using namespace std;

int N, M;
long long Dist[MAX];
vector<pair<pair<int, int>, int>> Edge;

void solve() {
    Dist[1] = 0;
    for (int i = 1; i <= N - 1; i++) {
        for (int j = 0; j < Edge.size(); j++) {
            int from = Edge[j].first.first;
            int to = Edge[j].first.second;
            int cost = Edge[j].second;

            if (Dist[from] == INF) continue;
            if (Dist[to] > Dist[from] + cost) {
                Dist[to] = Dist[from] + cost;
            }
        }
    }

    for (int i = 0; i < Edge.size(); i++) {
        int from = Edge[i].first.first;
        int to = Edge[i].first.second;
        int cost = Edge[i].second;

        if (Dist[from] == INF) continue;
        if (Dist[to] > Dist[from] + cost) {
            cout << -1 << '\n';
            return;
        }
    }

    for (int i = 2; i <= N; i++) {
        if (Dist[i] == INF) cout << -1 << '\n';
        else cout << Dist[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) Dist[i] = INF;
    for (int i = 0; i < M; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        Edge.push_back({{from, to}, cost});
    }

    solve();
}