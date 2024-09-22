#include <iostream>
#include <cmath>

using namespace std;

int N, a, b;

int main() {
    cin >> N >> a >> b;

    int diff = abs(a + b - N);

    int ans = 0;

    for (int i = diff; i < N; i++) {
        int c = pow(2, i);
        ans += c;
    }
    cout << ans;

}
