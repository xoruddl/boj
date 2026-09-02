#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

bool visited[203];
vector<vector<int>> graph;

void bfs(int x) {
    visited[x] = true;
    queue<int> q;
    q.push(x);
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int i = 0; i < graph[cur].size(); i++) {
            int num = graph[cur][i];
            if (num == 1) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    graph = computers;

    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(i);
            answer++;
        }
    }
    
    return answer;
}