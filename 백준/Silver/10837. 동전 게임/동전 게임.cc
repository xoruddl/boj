#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int K, C, M, N;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> K >> C;
    int CC = C;
    while (CC--) {
        cin >> M >> N;

        if (M == N) {
            cout << 1 << '\n';
            continue;
        }
        
        int r = K - max(M, N);  // 남은 게임수
        int diff = abs(M - N);
        
        if (M > N) {
            if (diff - r <= 2) {
                cout << 1 << '\n';
                continue;
            }
            else {
                cout << 0 << '\n';
                continue;
            }
        }
        
        if (M < N) {
            if (diff - r <= 1) {
                cout << 1 << '\n';
                continue;
            }
            cout << 0 << '\n';
        }
    }
}