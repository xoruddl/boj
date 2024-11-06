#include <iostream>

using namespace std;

string input;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> input;

    string ans = "{";
    for (int i = 0; i < input.size() - 2; i++) {
        for (int j = i + 1; j < input.size() - 1; j++) {
            string val;

            for (int k = i; k >= 0; k--) {
                val += input[k];
            }
            for (int k = j; k > i; k--) {
                val += input[k];
            }
            for (int k = input.size() - 1; k > j; k--) {
                val += input[k];
            }

            if (ans > val) ans = val;
        }
    }
    cout << ans;
}