#include <iostream>

using namespace std;

int L, P;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> L >> P;
    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        cout << a - L * P << " ";
    }
}