#include <iostream>
#include <cmath>

using namespace std;

int N;
int ans;

int solve(int n) {
    if (n == 1) return 0;

    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result = ((double)result / i) * (i - 1);
        }
    }
    if (n != 1) result = ((double)result / n) * (n - 1);
    return (int) result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        ans += solve(i);
    }
    cout << ans << '\n';
    return 0;
}