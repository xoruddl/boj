#include <iostream>

using namespace std;

int X;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> X;

    int i = 1;
    while (X > i) {
        X -= i;
        i++;
    }

    if (i % 2 == 1) {
        cout << i + 1 - X << "/" << X << '\n';
    } else {
        cout << X << "/" << i + 1 - X << '\n';
    }
    return 0;
}