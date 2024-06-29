#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> v(3);

    while (1) {
        cin >> v[0] >> v[1] >> v[2];

        if (v[0] == 0 && v[1] == 0 && v[2] == 0) {
            break;
        }

        sort(v.begin(), v.end());

        if (pow(v[0], 2) + pow(v[1], 2) == pow(v[2], 2)) {
            cout << "right\n";
        }
        else {
            cout << "wrong\n";
        }
    }
}
