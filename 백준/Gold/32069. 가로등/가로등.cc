#include <iostream>
#include <queue>
#include <set>

#define ll long long

using namespace std;

ll L, a;
int N, K;
ll dx[] = {-1, 1};
queue<pair<ll, ll>> q;
set<ll> visited;

bool isPossible(ll x) {
    return 0 <= x && x <= L;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> L >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a;
        q.push({a, 0});
        visited.insert(a);
    }

    while (!q.empty()) {
        ll here = q.front().first;
        ll dist = q.front().second;
        q.pop();

        cout << dist << '\n';
        --K;

        if (K == 0) {
            return 0;
        }

        for (int i = 0; i < 2; i++) {
            ll there = here + dx[i];

            if (isPossible(there) && !visited.count(there)) {
                q.push({there, dist + 1});
                visited.insert(there);
            }
        }
    }
}