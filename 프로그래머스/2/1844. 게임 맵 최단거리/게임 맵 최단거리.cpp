#include <vector>
#include <iostream>
#include <queue>
using namespace std;

#define MAX 987654321

bool visited[103][103];
int n, m;
int answer = 0;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<vector<int>> graph;

void bfs(int y, int x) {
    graph[y][x] = 1;
    visited[y][x] = true;
    
    queue<pair<int, int>> q;
    q.push({y, x});
    
    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                continue;
            }
            if (visited[ny][nx] || graph[ny][nx] == 0) {
                continue;
            }
            graph[ny][nx] = graph[cy][cx] + 1;
            q.push({ny, nx});
            visited[ny][nx] = true;
        }
    }
}

int solution(vector<vector<int>> maps) {
    
    n = maps.size();
    m = maps[0].size();
    graph.assign(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maps[i][j] == 1) {
                graph[i][j] = MAX;
            } else {
                graph[i][j] = 0;
            }
        }
    }
    
    bfs(0, 0);
    
    if (graph[n - 1][m - 1] == MAX) {
        return -1;
    } else {
        return graph[n-1][m-1];
    }
    
}