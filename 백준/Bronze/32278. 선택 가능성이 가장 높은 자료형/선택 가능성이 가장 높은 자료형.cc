#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    long long N;

    cin >> N;
    if (N >= -32768 && N <= 32767) {
        cout << "short";
    }
    else if (N >= INT_MIN && N <= INT_MAX) {
        cout << "int";
    }
    else {
        cout << "long long";
    }
}