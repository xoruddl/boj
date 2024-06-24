#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, r;
int result;
int dist[101];
int items[101];
vector<pair<int, int>> v[101];

void Input() {
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) {
        cin >> items[i];
    }

    int a, b, l;
    for (int i = 0; i < r; i++) {
        cin >> a >> b >> l;
        v[a].push_back({b, l});
        v[b].push_back({a, l});
    }
}

void fc(int start) {
    int cnt = 0;
    queue<int> q;
    q.push(start);

    for (int i = 1; i <= n; i++) {
        dist[i] = 987654321;
    }
    dist[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        int distance = dist[node];
        q.pop();

        for (int i = 0; i < v[node].size(); i++) {
            int next_node = v[node][i].first;
            int next_dist = v[node][i].second;

            if (dist[next_node] > distance + next_dist) {
                dist[next_node] = distance + next_dist;
                q.push(next_node);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i] <= m) {
            cnt += items[i];
        }
    }

    result = max(cnt, result);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();

    for (int i = 1; i <= n; i++) {
        fc(i);
    }

    cout << result << '\n';
    return 0;
}