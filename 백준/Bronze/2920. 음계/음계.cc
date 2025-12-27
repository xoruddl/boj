#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string n, original;

int main() {

    for (int i = 0; i < 8; i++) {
        char num;
        cin >> num;
        n.push_back(num);
        original.push_back(num);
    }
    sort(n.begin(), n.end());
    if (original == n) {
        cout << "ascending";
    }
    else {
        sort(n.begin(), n.end(), [](int a, int b) {
            return a > b;
        });
        if (original == n) {
            cout << "descending";
        }
        else {
            cout << "mixed";
        }
    }

    return 0;
}