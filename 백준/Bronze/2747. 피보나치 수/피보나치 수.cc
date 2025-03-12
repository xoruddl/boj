#include <iostream>

using namespace std;

int N;

int fibo(int n) {
    int f[100];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    cout << fibo(N);
}