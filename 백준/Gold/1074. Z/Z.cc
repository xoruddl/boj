#include <iostream>
#include <cmath>

using namespace std;

int N, r, c;
int ans;

void fc(int x, int y, int size) {
    if (c == x && r == y) { // 열과 행 일치
        cout << ans;
        return;
    }
    else if (c < x + size && r < y + size && c >= x && r >= y) {
        fc(x, y, size / 2);
        fc(x + size / 2, y, size / 2);
        fc(x, y + size / 2, size / 2);
        fc(x + size / 2, y + size / 2, size / 2);
    }
    else {
        ans += size * size;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> r >> c;
    fc(0, 0, pow(2, N));
    return 0;
}