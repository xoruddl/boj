#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, start;
vector<pair<int, int>> tree[100001];
int farNode, maxCost, curCost;
bool visited[100001];

void dfs(int cur) {
    visited[cur] = true;

    for (int i = 0; i < tree[cur].size(); i++) {
        int nextNode = tree[cur][i].first;
        int addCost = tree[cur][i].second;
        if (!visited[nextNode]) {
            curCost += addCost;
            visited[nextNode] = true;
            if (maxCost < curCost) {
                maxCost = curCost;
                farNode = nextNode;
            }
            dfs(nextNode);
            visited[nextNode] = false;
            curCost -= addCost;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int p, c, cost;
        cin >> p >> c >> cost;
        tree[p].push_back({c, cost});
        tree[c].push_back({p, cost});
    }

    dfs(1); // 루트에서 가장 먼 곳 찾기
//    cout << farNode << " " << maxCost;

    memset(visited, false, sizeof(visited));

    int startNode = farNode;
    maxCost = 0;
    dfs(startNode);

//    cout << farNode << " " << maxCost;
    cout << maxCost;
    return 0;
}