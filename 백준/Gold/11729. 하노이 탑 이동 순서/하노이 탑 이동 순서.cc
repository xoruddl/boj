#include <iostream>

using namespace std;

int N;

void fc(int a, int b, int n) {
    if (n == 1) {
        cout << a << " " << b << '\n';
        return;
    }
    fc(a, 6 - a - b, n - 1);
    cout << a << " " << b << '\n';
    fc(6 - a - b, b, n - 1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    cout << (1 << N) - 1 << '\n';
    fc(1, 3, N);
}