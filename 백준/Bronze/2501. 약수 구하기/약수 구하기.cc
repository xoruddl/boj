#include <iostream>

using namespace std;

int N, K;
int ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        if (N % i == 0) {
            K--;
            ans = i;
        }
        if (K == 0) {
            break;
        }
    }

    if (K != 0) {
        cout << 0;
    }
    else {
        cout << ans;
    }
}