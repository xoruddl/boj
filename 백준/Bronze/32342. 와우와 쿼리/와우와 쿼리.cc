#include <iostream>

using namespace std;

int q;

int main() {
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'W' && s[i + 1] == 'O' && s[i + 2] == 'W') {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}