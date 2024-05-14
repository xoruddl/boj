#include <iostream>

using namespace std;

int dp[21][21][21];

int Solve(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;

    if (a > 20 || b > 20 || c > 20) {
        return Solve(20, 20, 20);
    }

    if (dp[a][b][c]) return dp[a][b][c];

    if (a < b && b < c) {
        dp[a][b][c] = Solve(a, b, c - 1) + Solve(a, b - 1, c - 1) - Solve(a, b - 1, c);
        return dp[a][b][c];
    }

    dp[a][b][c] = Solve(a - 1, b, c) + Solve(a - 1, b - 1, c) + Solve(a - 1, b, c - 1) - Solve(a - 1, b - 1, c - 1);
    return dp[a][b][c];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1) break;

        cout << "w(" << a << ", " << b << ", " << c << ") = " << Solve(a, b, c) << '\n';
    }
    return 0;
}