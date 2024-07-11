#include <iostream>

using namespace std;

int N;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    while (N--) {
        int a, b;
        cin >> a >> b;
        cout << lcm(a, b) << '\n';
    }
    return 0;
}
