#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#define MAX 987654321

struct P {
    int cost;
    int node;
    
    bool operator < (const P& o) const {
        return cost > o.cost;
    }
};

vector<vector<P>> graph;
vector<int> dist;

void fc() { // 다익스트라
    dist[1] = 0;
    
    priority_queue<P> pq;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        P p = pq.top();
        int cost = p.cost;
        int cur = p.node;
        pq.pop();
        
        for (int i = 0; i < graph[cur].size(); i++) {
            P next = graph[cur][i];
            if (dist[next.node] > dist[cur] + next.cost) {
                dist[next.node] = dist[cur] + next.cost;
                pq.push({dist[next.node], next.node});
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    int m = road.size();
    dist.assign(N + 1, MAX);
    graph.assign(N + 1, vector<P>());
    
    for (auto r : road) {
        graph[r[0]].push_back({r[2], r[1]});
        graph[r[1]].push_back({r[2], r[0]});
    }
    
    fc();
    
    for (int i = 1; i <= N; i++) {
        // cout << dist[i] << '\n';
        if (dist[i] <= K) {
            answer++;
        }
    }

    return answer;
}