#include <iostream>

using namespace std;

int N, ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j++) {
            int k = N - i - j;
            if (j > k) break;
            if (i + j > k) ans++;
        }
    }
    cout << ans;
}