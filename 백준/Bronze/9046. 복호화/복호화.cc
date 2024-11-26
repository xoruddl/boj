#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
string s;
string code = "abcdefghijklmnopqrstuvwxyz";

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;
    cin.ignore();
    while (T--) {
        getline(cin, s);

        vector<int> v(26);
        fill(v.begin(), v.end(), 0);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue;
            s[i] = code[s[i] - 'a'];

            v[s[i] - 'a']++;
        }

        int m = -1;
        char M;
        for (int i = 0; i < 26; i++) {
            if (m < v[i]) {
                m = v[i];
                M = i + 'a';
            }
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (m == v[i]) {
                cnt++;
            }
            if (cnt >= 2) break;
        }

        if (cnt >= 2) {
            cout << "?" << '\n';
        }
        else cout << M << '\n';
    }

}