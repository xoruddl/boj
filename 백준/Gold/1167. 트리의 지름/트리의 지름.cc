#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int V, maxDist, maxNode;
bool visited[100003];
vector<pair<int,int>> v[100003];

void dfs(int node, int dist) {

    if (visited[node]) {    // 방문한 노드면 return
        return;
    }

    if (maxDist < dist) {
        maxDist = dist;
        maxNode = node;
    }
    visited[node] = true;

    for (int i = 0; i < v[node].size(); i++) {
        int nextNode = v[node][i].first;
        int nextDist = v[node][i].second;
        dfs(nextNode, nextDist + dist);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> V;
    for (int i = 0; i < V; i++) {
        int start;
        cin >> start;

        int end, edge;
        while (1) {
            cin >> end;
            if (end == -1) break;
            cin >> edge;
            v[start].push_back({end, edge});
        }
    }

    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    maxDist = 0;
    dfs(maxNode, 0);

    cout << maxDist;
    return 0;
}