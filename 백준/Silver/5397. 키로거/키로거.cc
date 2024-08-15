#include <iostream>
#include <list>

using namespace std;

int T;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;
    while (T--) {
        list<char> l = {};
        auto cursor = l.begin();

        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '<') {
                if (cursor != l.begin()) cursor--;
            } else if (s[i] == '>') {
                if (cursor != l.end()) cursor++;
            } else if (s[i] == '-') {
                if (cursor != l.begin()) {
                    cursor--;
                    cursor = l.erase(cursor);
                }
            } else {
                l.insert(cursor, s[i]);
            }
        }
        for (auto c : l) cout << c;
        cout << '\n';
    }
}