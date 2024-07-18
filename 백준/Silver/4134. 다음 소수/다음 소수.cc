#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull T, N;

ull powerMod(ull a, ull b, ull n) {
    ull result = 1;
    a %= n;

    while (b) {
        if (b % 2 == 1) result = (result * a) % n;
        b /= 2;
        a = (a * a) % n;
    }
    return result;
}

bool MRtest(ull x, ull base) {
    if (base % x == 0) return true;

    ull k = x - 1;
    while (1) {
        ull mod = powerMod(base, k, x);
        if (mod == x - 1) return true;
        if (k % 2 == 1) return (mod == 1 || mod == x - 1);
        k /= 2;
    }
}

bool isPrime(ull n) {
    if (n == 1) return false;
    ull a[] = {2, 7, 61};

    for (int i = 0; i < 3; i++) {
        if (!MRtest(n, a[i])) {
            return false;
            break;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while (T--) {
        cin >> N;
        if (N == 0) cout << 2 << '\n';
        else {
            for (ull i = N; ;i++) {
                if (isPrime(i)) {
                    cout << i << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}