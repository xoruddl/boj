#include <iostream>

using namespace std;

typedef long long ll;

ll n, sum, s = 1;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    while (n) {
        if (n & 1) {
            sum += s;
        }
        s *= 3;
        n >>= 1;
    }
    cout << sum;
}
