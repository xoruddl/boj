#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N;
map<int, int> m;
vector<int> v;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for (auto a: v) {
        if (m.find(a) == m.end()) {
            m.insert({a, 1});
        }
    }
    for (auto a: m) {
        cout << a.first << " ";
    }
    return 0;
}
