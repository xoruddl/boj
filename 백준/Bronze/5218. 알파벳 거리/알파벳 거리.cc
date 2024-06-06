#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    string a, b;
    cin >> t;

    while (t--) {
        cin >> a >> b;
        vector<int> v;
        for (int i = 0; i < a.size(); i++) {
            if (b[i] >= a[i]) {
                v.push_back(b[i] - a[i]);
            }
            else {
                v.push_back((b[i] + 26) - a[i]);
            }
        }
        cout << "Distances: ";
        for (int i = 0; i < a.size(); i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}