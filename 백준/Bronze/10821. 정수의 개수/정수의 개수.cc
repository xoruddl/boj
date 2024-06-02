#include <iostream>
#include <string>

using namespace std;

string s;

int main() {
    getline(cin, s);

    int cnt = 1;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',') {
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}