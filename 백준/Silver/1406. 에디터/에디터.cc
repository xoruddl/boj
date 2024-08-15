#include <iostream>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    string s;
    cin >> s;
    cin >> n;

    list<char> l;
    for (auto c : s) l.push_back(c);
    auto cursor = l.end();

    while (n--) {
        char op;
        cin >> op;
        if (op == 'P') {
            char add;
            cin >> add;
            l.insert(cursor, add);
        } else if (op == 'L') {
            if (cursor != l.begin()) cursor--;
        } else if (op == 'D') {
            if (cursor != l.end()) cursor++;
        } else {
            if (cursor != l.begin()) {
                cursor--;
                cursor = l.erase(cursor);
            }
        }
    }
    for (auto c : l) cout << c;
}