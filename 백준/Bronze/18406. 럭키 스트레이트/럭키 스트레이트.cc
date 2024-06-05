#include <iostream>
#include <string>

using namespace std;

string num;
int sum1, sum2;

int main() {
    cin >> num;

    for (int i = 0; i < num.size() / 2; i++) {
        sum1 += num[i] - '0';
    }

    for (int i = num.size() / 2; i < num.size(); i++) {
        sum2 += num[i] - '0';
    }

    if (sum1 == sum2) {
        cout << "LUCKY" << '\n';
    }
    else {
        cout << "READY" << '\n';
    }
    return 0;
}