#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string add(string a, string b) {
    string res;

    int maxLen = max(a.size(), b.size());
    a = string(maxLen - a.size(), '0') + a;
    b = string(maxLen - b.size(), '0') + b;

    int carry = 0;
    for (int i = maxLen - 1; i >= 0; i--) {
        int digitSum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = digitSum / 10;
        res += (digitSum % 10) + '0';
    }

    if (carry > 0) res += carry + '0';

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string a, b;
    cin >> a >> b;

    string sum = add(a, b);
    cout << sum;
    return 0;
}