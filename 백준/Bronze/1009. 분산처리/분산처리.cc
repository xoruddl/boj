#include <iostream>

using namespace std;

int T;

int main() {
    cin >> T;

    int TT =  T;
    while (TT--) {
        int a, b;
        cin >> a >> b;

        int tmp = 1;
        for (int i = 0; i < b; i++) {
            tmp = (tmp * a) % 10;
        }
        if (tmp == 0) {
            cout << 10 << '\n';
        }
        else {
            cout << tmp << '\n';
        }
    }
}