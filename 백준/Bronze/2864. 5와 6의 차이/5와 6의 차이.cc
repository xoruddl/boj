#include <iostream>
#include <string>

using namespace std;

string a, b;

int main() {
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '6') a[i] = '5';
    }
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == '6') b[i] = '5';
    }
    int a1, b1;
    a1 = stoi(a);
    b1 = stoi(b);
    cout << a1 + b1 << " ";

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '5') a[i] = '6';
    }
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == '5') b[i] = '6';
    }

    a1 = stoi(a);
    b1 = stoi(b);
    cout << a1 + b1 << '\n';
    return 0;
}