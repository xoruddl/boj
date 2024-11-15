#include <iostream>

using namespace std;

int T;
int X1, Y1, r1, x2, y2, r2;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;
    while (T--) {
        cin >> X1 >> Y1 >> r1 >> x2 >> y2 >> r2;

        int d = (X1 - x2) * (X1 - x2) + (Y1 - y2) * (Y1 - y2);
        int cond1 = (r1 - r2) * (r1 - r2);
        int cond2 = (r1 + r2) * (r1 + r2);
        if (d == 0) {
            if (cond1 == 0) {
                cout << -1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if (d == cond1 || d == cond2) {
            cout << 1 << '\n';
        }
        else if (cond1 < d && d < cond2) {
            cout << 2 << '\n';
        }
        else cout << 0 << '\n';
    }
}
