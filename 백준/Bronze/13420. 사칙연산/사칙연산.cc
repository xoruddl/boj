#include <iostream>

using namespace std;

int T;

int main() {
    cin >> T;

    while (T--) {
        long long a, b, ans;
        char op, equal;
        cin >> a >> op >> b >> equal >> ans;

        if (op == '+') {
            if (a + b == ans) {
                cout << "correct" << '\n';
            }
            else {
                cout << "wrong answer" << '\n';
            }
        }
        else if (op == '-') {
            if (a - b == ans) {
                cout << "correct" << '\n';
            }
            else {
                cout << "wrong answer" << '\n';
            }
        }
        else if (op == '*') {
            if (a * b == ans) {
                cout << "correct" << '\n';
            }
            else {
                cout << "wrong answer" << '\n';
            }
        }
        else if (op == '/') {
            if (a / b == ans) {
                cout << "correct" << '\n';
            }
            else {
                cout << "wrong answer" << '\n';
            }
        }
    }
    return 0;
}