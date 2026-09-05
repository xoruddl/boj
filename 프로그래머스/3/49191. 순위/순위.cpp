#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define MAX 987654321

vector<vector<int>> graph;
int N;
int answer = 0;

void fc() { // 플로이드 워셜
    
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (graph[i][k] == 1 && graph[k][j] == 1) {
                    graph[i][j] = 1;
                }
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int j = 1; j <= N; j++) {
            if (graph[i][j] == 1 || graph[j][i] == 1) {
                cnt++;
            }
        }
        if (cnt == N - 1) {
            answer++;
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    N = n;
    graph.assign(n + 1, vector<int>(n + 1, MAX));
    
    for (auto r: results) {
        graph[r[0]][r[1]] = 1;
    }
    
    fc();
    
    return answer;
}