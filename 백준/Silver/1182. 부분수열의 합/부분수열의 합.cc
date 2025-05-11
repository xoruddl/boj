#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> v;
int ans;

void fc(int cur, int sum) {
    if (cur == N) {
        if (sum == S) {
            ans++;
        }
        return;
    }
    fc(cur + 1, sum);
    fc(cur + 1, sum + v[cur]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        v.push_back(a);
    }
    fc(0, 0);
    if (S == 0) ans--;
    cout << ans;
}