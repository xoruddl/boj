#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int x;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> x;
    if (x % 3 == 0) {
        cout << 'S';
    }
    else if (x % 3 == 1) {
        cout << 'U';
    }
    else {
        cout << 'O';
    }
}
