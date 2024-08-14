#include <iostream>

using namespace std;

int main() {
    unsigned long long a, b;
    cin >> a >> b;

    if (a > b) {
        unsigned long long tmp = a;
        a = b;
        b = tmp;
    }
    if (a == b) {
        cout << 0 << '\n';
    } else {
        cout << b - a - 1 << '\n';
        for (unsigned long long i = a + 1; i < b; i++) {
            cout << i << " ";
        }
    }
}