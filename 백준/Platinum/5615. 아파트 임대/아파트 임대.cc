#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int N, ans;
vector<ull> apt;
ull p[3] = {2, 7, 61};

ull powerMod(ull a, ull b, ull mod) {
    ull result = 1;
    a %= mod;
    while (b) {
        if (b % 2 == 1) {
            result = (result * a) % mod;
        }
        b /= 2;
        a = (a * a) % mod;
    }
    return result;
}

bool miller(ull n, ull b) {
    if (b % n == 0) return true;

    ull k = n - 1;
    while (1) {
        ull temp = powerMod(b, k, n);
        if (temp == n - 1) return true;
        if (k % 2 == 1) return (temp == 1 || temp == n - 1);
        k /= 2;
    }
}

bool isPrime(ull n) {
    for (int i = 0; i < 3; i++) {
        if (!miller(n, p[i])) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        ull a; cin >> a;
        if (isPrime(2 * a + 1)) ans++;
    }

    cout << ans;
    return 0;
}