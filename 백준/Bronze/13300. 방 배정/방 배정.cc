#include <iostream>

using namespace std;

int N, K;
int arr[2][7];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    while (N--) {
        int S, Y;
        cin >> S >> Y;
        arr[S][Y]++;
    }

    int ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= 6; j++) {
            ans += arr[i][j] / K;
            if (arr[i][j] % K) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}