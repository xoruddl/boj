#include <iostream>

using namespace std;

int T;
int coin[4] = {25, 10, 5, 1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    int TT = T;
    while (TT--) {
        int C;
        cin >> C;

        for (int i = 0; i < 4; i++) {
            cout << C / coin[i] << " ";
            C = C % coin[i];
        }
        cout << '\n';
    }
}