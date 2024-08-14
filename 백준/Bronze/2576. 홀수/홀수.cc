#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {
    int a;
    int sum = 0;
    for (int i = 0; i < 7; i++) {
        cin >> a;
        if (a % 2 == 1) {
            sum += a;
            v.push_back(a);
        }
    }

    if (v.size() == 0) {
        cout << -1;
        return 0;
    }
    sort(v.begin(), v.end());
    cout << sum << '\n' << v[0];
    return 0;
}