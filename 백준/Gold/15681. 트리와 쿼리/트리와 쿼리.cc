#include <iostream>
#include <vector>

using namespace std;

int N, R, Q;
int dp[100001];
bool visited[100001];
vector<int> v[100001];

void dfs(int node, int parent) {
    visited[node] = true;
    for (int i = 0; i < v[node].size(); i++) {
        int next = v[node][i];
        if (visited[next]) {
            continue;
        }
        dfs(next, node);
    }
    if (parent != -1) {
        dp[parent] += dp[node];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> R >> Q;
    fill_n(dp, 100001, 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(R, -1);
    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        cout << dp[q] << '\n';
    }
}
