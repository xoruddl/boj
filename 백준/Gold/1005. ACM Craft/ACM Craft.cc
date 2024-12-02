#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T;
int N, K, W;
vector<int> D;
vector<vector<int>> v;
vector<int> dp;
vector<int> indegree;

void bfs() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            dp[i] = D[i];
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];
            if (next > 0) {
                dp[next] = max(dp[next], dp[cur] + D[next]);
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> K;
        D.resize(N + 1);
        dp.resize(N + 1);
        indegree.resize(N + 1);
        v.resize(N + 1);

        for (int j = 1; j <= N; j++) {
            cin >> D[j];    // 건설시간
        }
        for (int k = 1; k <= K; k++) {
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
            indegree[y]++;
        }
        cin >> W;
        bfs();
        cout << dp[W] << '\n';

        D.clear();
        dp.clear();
        indegree.clear();
        v.clear();
    }
    return 0;
}