#include <string>
#include <vector>
#include <queue>

using namespace std;

#define MAX 203

bool visited[MAX];
queue<int> q;

void bfs(int node, const vector<vector<int>> &nodes) {
    visited[node] = true;
    q.push(node);
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int i = 0; i < nodes[cur].size(); i++) {
            int next = i;
            if (visited[next] || nodes[cur][i] == 0) {
                continue;
            }
            q.push(next);
            visited[next] = true;
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(i, computers);
            answer++;
        }
    }
    
    return answer;
}