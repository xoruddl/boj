#include <iostream>

using namespace std;

int N;
int coin[] = {500, 100, 50, 10, 5, 1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    N = 1000 - N;

    int ans = 0;
    for (int i = 0; i < 6; i++) {
        ans += N / coin[i];
        N %= coin[i];
    }
    cout << ans;
}