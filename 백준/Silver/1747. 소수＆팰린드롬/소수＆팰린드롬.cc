#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }

    return true;
}

bool checkPalin(string s) {
    string s1, s2;

    s1 = s;
    reverse(s.begin(), s.end());
    s2 = s;

    if (s1 == s2) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = n; ; i++) {
        if (isPrime(i) && checkPalin(to_string(i))) {
            cout << i;
            break;
        }
    }
    return 0;
}