#include <iostream>

using namespace std;

int N;

int main() {
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= 2 * N - 1; i++) {
        if (i <= N) {
            for (int j = 1; j <= i; j++) {
                cout << "*";
            }
            cout << '\n';
        }
        else {
            for (int j = i; j <= 2 * N - 1; j++) {
                cout << "*";
            }
            cout << '\n';
        }
    }
}