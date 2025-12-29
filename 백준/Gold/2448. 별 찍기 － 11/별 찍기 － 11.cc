#include <iostream>
using namespace std;

#define MAX 3072

int N;
char MAP[2 * MAX + 3][2 * MAX + 3];

void fc(int n, int y, int x) {
    if (n == 3) {
        MAP[y][x] = '*';
        MAP[y + 1][x - 1] = '*';
        MAP[y + 1][x + 1] = '*';
        MAP[y + 2][x - 2] = '*';
        MAP[y + 2][x - 1] = '*';
        MAP[y + 2][x] = '*';
        MAP[y + 2][x + 1] = '*';
        MAP[y + 2][x + 2] = '*';

        return;
    }

    fc(n / 2, y, x);
    fc(n / 2, y + n / 2, x - n / 2);
    fc(n / 2, y + n / 2, x + n / 2);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    for (int i = 1; i <= 2 * N; i++) {
        for (int j = 1; j <= 2 * N; j++) {
            MAP[i][j] = ' ';
        }
    }

    fc(N, 1, N);

    for (int i = 1; i <= 2 * N - 1; i++) {
        for (int j = 1; j <= 2 * N - 1; j++) {
            cout << MAP[i][j];
        }
        cout << "\n";
    }
}