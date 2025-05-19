#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<vector<int>> graph;
bool visited[1003];
queue<int> q;

void dfs(int cur) {
    visited[cur] = true;
    cout << cur << " ";

    for (int i = 0; i < graph[cur].size(); i++) {
        int nextNode = graph[cur][i];
        if (!visited[nextNode]) {
            visited[nextNode] = true;
            dfs(nextNode);
        }
    }
}

void bfs(int start) {
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (int i = 0; i < graph[cur].size(); i++) {
            int nextNode = graph[cur][i];
            if (!visited[nextNode]) {
                q.push(nextNode);
                visited[nextNode] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M >> V;
    graph.resize(1001);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(V);

    fill(visited, visited + 1003, false);

    cout << '\n';
    bfs(V);
}