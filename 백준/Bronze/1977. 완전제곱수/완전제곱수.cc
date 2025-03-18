#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int a, b;
int ans = 987654321;
int sum;
int cnt;

int main() {
    cin >> a >> b;

    for (int i = 1; i <= sqrt(max(a, b)); i++) {
        if (i * i <= max(a, b) && i * i >= min(a, b)) {
            if (ans >= i * i) {
                ans = i * i;
            }
            sum += i * i;
            cnt++;
        }
    }
    if (cnt == 0) cout << -1 << '\n';
    else {
        cout << sum << '\n' << ans << '\n';
    }
    return 0;
}