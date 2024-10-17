#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v(53);

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v[a]++;
    }

    int ans = 0;
    for (int i = 0; i < 51; i++) {
        if (v[i] == i) {
            ans = i;
        }
    }

    if (ans == 0) {
        if (v[0]) ans = -1;
    }

    cout << ans;
    return 0;
}