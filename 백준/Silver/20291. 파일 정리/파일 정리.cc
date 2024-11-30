#include <iostream>
#include <map>
#include <string>

using namespace std;

int N;
map<string, int> mp;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        string t = "";
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '.') {
                t = s.substr(j + 1, s.size());
                break;
            }
        }
        mp[t]++;
    }
    for (auto p: mp) {
        cout << p.first << " " << p.second << '\n';
    }
}
