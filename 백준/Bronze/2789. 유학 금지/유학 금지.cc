#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char cambridge[9] = {'C', 'A', 'M', 'B', 'R', 'I', 'D', 'G', 'E'};
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;

    sort(cambridge, cambridge + 9);
    for (int i = 0; i < s.size(); i++) {
        if (!binary_search(cambridge, cambridge + 9, s[i])) {
            cout << s[i];
        }
    }
    return 0;
}