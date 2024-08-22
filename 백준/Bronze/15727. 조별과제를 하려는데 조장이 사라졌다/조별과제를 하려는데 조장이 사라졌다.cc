#include <iostream>

using namespace std;

int main() {
    int L;
    cin >> L;
    int ans = 0;
    if (L % 5) {
        cout << L / 5 + 1;
    } else {
        cout << L / 5;
    }
    return 0;
}