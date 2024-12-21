#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long N;
    cin >> N;

    long long ans = 1;
    for (int i = 2; i <= N; i++) {
        ans *= i;
    }
    cout << ans;
}