#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int farDist;
vector<vector<int>> graph;
bool visited[20003];
int dist[20003];
queue<int> q;

void bfs() {
    dist[1] = 0;
    visited[1] = true;
    q.push(1);
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (visited[next]) continue;
            visited[next] = true;
            q.push(next);
            dist[next] = dist[cur] + 1;
            if (dist[next] > farDist) {
                farDist = dist[next];
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int m = edge.size();
    
    graph.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a = edge[i][0];
        int b = edge[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs();
    
    for (int i = 1; i <= n; i++) {
        if (dist[i] == farDist) {
            answer++;
        }
    }
    
    return answer;
}