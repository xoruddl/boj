#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visited[203];
vector<vector<int>> graph;
int N;

void dfs(int x) {
    visited[x] = true;
    
    for (int i = 0; i < N; i++) {
        if (graph[x][i] == 1 && !visited[i]) {
            visited[i] = true;
            dfs(i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    graph = computers;
    N = n;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            answer++;
        }
    }
    
    return answer;
}