#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> graph;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    int m = results.size();

    graph.assign(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < m; i++) {
        int a = results[i][0];
        int b = results[i][1];
        graph[a][b] = true;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][k] && graph[k][j]) {
                    graph[i][j] = true;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] || graph[j][i]) {
                cnt++;
            }
        }
        if (cnt == n - 1) {
            answer++;
        }
    }
    return answer;
}