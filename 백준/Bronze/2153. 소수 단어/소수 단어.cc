#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string s;
int sum;

bool isPrime(int n) {
    if (n == 0) return false;
    if (n == 1) return true;

    for (int i = 2; i <= sqrt(sum); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            sum += s[i] - 'A' + 27;
        }
        else if (s[i] >= 'a' && s[i] <= 'z') {
            sum += s[i] - 'a' + 1;
        }
    }
    if (isPrime(sum)) {
        cout << "It is a prime word." << '\n';
    }
    else {
        cout << "It is not a prime word." << '\n';
    }
    return 0;
}