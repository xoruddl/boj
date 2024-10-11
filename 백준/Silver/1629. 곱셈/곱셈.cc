#include <iostream>

using namespace std;

typedef long long ll;

ll A, B, C;
ll ans;

ll powerMod(ll a, ll b, ll mod) {
    ll result = 1;
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> A >> B >> C;

    cout << powerMod(A, B, C);
    return 0;
}