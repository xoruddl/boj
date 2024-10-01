#include <iostream>

using namespace std;

int N;
string video[64];

void fc(int size, int y, int x) {
    char curr = video[y][x];

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (video[i][j] != curr) {
                cout << "(";
                fc(size / 2, y, x);
                fc(size / 2, y, x + size / 2);
                fc(size / 2, y + size / 2, x);
                fc(size / 2, y + size / 2, x + size / 2);
                cout << ")";
                return;
            }
        }
    }
    cout << curr;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> video[i];
    }

    fc(N, 0, 0);
    return 0;

}