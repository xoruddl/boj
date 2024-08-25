#include <iostream>

using namespace std;

int a, b, n;

int main() {
    cin >> a >> b >> n;

    if (a % b == 0) {
        cout << 0;
        return 0;
    }
    a = a % b;

    int ans = 0;

    while (n--) {
        a *= 10;
        ans = a / b;
        a = a % b;
    }
    cout << ans;
    return 0;
}
