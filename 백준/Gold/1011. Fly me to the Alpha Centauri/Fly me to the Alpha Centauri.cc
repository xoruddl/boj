#include <iostream>
#include <cmath>

using namespace std;

int T;
long long x, y;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> x >> y;
        long long move, max = 0;
        while (max * max <= y - x) {
            max++;
        }
        max--;
        move = 2 * max - 1;
        long long rem = y - x - max * max;
        rem = (long long) ceil((double) rem / (double)max);
        move += rem;
        cout << move << '\n';
    }
}