#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int a, b;
        cin >> a >> b;
        cout << a + b << '\n';
    }
}