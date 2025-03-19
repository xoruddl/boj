#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        A.push_back(a);
    }

    int ans = 0;
    for (int i = 0; i < 20; i++) {
        int bit = (1 << i);
        int cnt = 0;
        for (auto n : A) {
            if (bit & n) {
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }

    cout << ans;
}