#include <iostream>
#include <vector>

using namespace std;

long long N;

long long solve (long long n) {
    double ans = n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            ans *= (1.0 - (1.0 / (double) i));
        }
    }
    if (n != 1) ans *= (1.0 - (1.0 / (double) n));
    return (long long) ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    cout << solve(N);
    return 0;
}