#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, ans;
bool visited[202];
vector<vector<int>> Computers;

void bfs(int idx) {
    visited[idx] = true;
    
    queue<int> q;
    q.push(idx);
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int i = 0; i < N; i++) {
            if (visited[i]) continue;
            if (Computers[cur][i] == 1) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    N = n;
    Computers = computers;
    
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            bfs(i);
            ans++;
        }
    }
    
    return ans;
}