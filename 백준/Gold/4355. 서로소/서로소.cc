#include <iostream>
#include <cmath>

using namespace std;

int N;

int solve(int n) {
    if (n == 1) return 0;
    double ans = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            ans = (ans / i) * (i - 1);
        }
    }
    if (n != 1) ans = (ans / n) * (n - 1);
    return (int) ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (1) {
        cin >> N;
        if (N == 0) break;

        cout << solve(N) << '\n';
    }
    return 0;
}
