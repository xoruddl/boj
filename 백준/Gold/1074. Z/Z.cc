#include <iostream>

using namespace std;

int fc(int n, int r, int c) {
    if (n == 0) return 0;
    int half = 1 << (n - 1);

    if (r < half && c < half) return fc(n - 1, r, c);
    if (r < half && c >= half) return half * half + fc(n - 1, r, c - half);
    if (r >= half && c < half) return 2 * half * half + fc(n - 1, r - half, c);
    return 3 * half * half + fc(n - 1, r - half, c - half);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, r, c;
    cin >> n >> r >> c;
    cout << fc(n, r, c);
}