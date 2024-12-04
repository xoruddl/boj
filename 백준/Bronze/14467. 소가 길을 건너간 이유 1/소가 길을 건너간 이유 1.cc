#include <iostream>
#include <vector>

using namespace std;

int N;
int ans;
vector<int> v[11];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
    }

    for (int i = 1; i <= 10; i++) {
        if (v[i].size() == 0) continue;

        for (int j = 0; j < v[i].size() - 1; j++) {
            if (v[i][j] != v[i][j + 1]) ans++;
        }
    }
    cout << ans;
}