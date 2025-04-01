#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C[3];
int D[3];
int H;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    for (int i = 0; i < 3; i++) {
        cin >> C[i] >> D[i];
    }
    cin >> H;

    H = H - (D[0] + D[1] + D[2]);

    if (H <= 0) {
        cout << 0;
        return 0;
    }

    int ans = 0;
    while (H > 0) {
        ans++;
        for(int i = 0; i < 3; i++) {
            if (ans % C[i] == 0) {
                H -= D[i];
                if (H <= 0) break;
            }
        }
    }
    cout << ans;
}
