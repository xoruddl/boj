#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    if (a == b + c) cout << a << "=" << b << "+" << c << '\n';
    else if (a == b - c) cout << a << "=" << b << "-" << c << '\n';
    else if (a == b / c) cout << a << "=" << b << "/" << c << '\n';
    else if (a == b * c) cout << a << "=" << b << "*" << c << '\n';
    else if (a + b == c) cout << a << "+" << b << "=" << c << '\n';
    else if (a - b == c) cout << a << "-" << b << "=" << c << '\n';
    else if (a * b == c) cout << a << "*" << b << "=" << c << '\n';
    else if (a / b == c) cout << a << "/" << b << "=" << c << '\n';
}