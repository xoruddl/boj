#include <iostream>

using namespace std;

int K;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> K;

    int n = 1;
    int cnt = 0;
    while (n < K) {
        n <<= 1;
    }
    int ans1 = n;

    if (ans1 == K) {
        cout << ans1 << " " << 0;
        return 0;
    }

    int cnt2 = 0;
    while (n) {
        if (!(n & K)) {
            n >>= 1;
            cnt2++;
        }
        else {
            cnt += cnt2;
            n >>= 1;
            cnt2 = 1;
        }
    }
    cout << ans1 << " " << cnt;
}