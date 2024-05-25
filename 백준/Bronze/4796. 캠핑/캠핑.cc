#include <iostream>
#include <algorithm>

using namespace std;

int p, l, v;

int main() {
    int cnt = 1;
    while (1) {
        cin >> l >> p >> v;
        if (l == 0 && p == 0 && v == 0) break;

        cout << "Case " << cnt << ": " << (v / p) * l + min(v % p, l) << '\n';
        cnt++;
    }
    return 0;
}