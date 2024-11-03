#include <iostream>

using namespace std;

int X;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> X;

    int ans = 0;
    while (X > 0) {
        if (X % 2 == 1) {
            ans++;
        }
        X /= 2;
    }
    cout << ans;
}
