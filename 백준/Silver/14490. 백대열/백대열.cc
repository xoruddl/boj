#include <iostream>
#include <numeric>
#include <string>

using namespace std;

string s, temp;
int n1, n2;

int main() {
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ':') {
            temp = s.substr(0, i);
            n1 = stoi(temp);

            temp = s.substr(i + 1, s.size());
            n2 = stoi(temp);
            break;
        }
    }
    int num = gcd(n1, n2);
    cout << n1 / num << ":" << n2 / num;
    return 0;
}
