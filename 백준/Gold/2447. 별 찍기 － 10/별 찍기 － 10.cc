#include <iostream>

using namespace std;

int N;

void fc(int n, int i, int j) {
    if ((i / n) % 3 == 1 && (j / n) % 3 == 1) {
        cout << " ";
    }
    else {
        if (n / 3 == 0) {
            cout << "*";
        }
        else {
            fc(n / 3, i, j);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fc(N, i, j);
        }
        cout << '\n';
    }
}