#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        v.push_back(a);
    }

    if (N == 1) {
        cout << "A";
    }
    else if (N == 2) {
        if (v[0] == v[1]) {
            cout << v[1];
        }
        else {
            cout << "A";
        }
    }
    else {
        int a = 0;
        if (v[1] != v[0]) {
            a = (v[2] - v[1]) / (v[1] - v[0]);
        }

        int b = v[1] - v[0] * a;

        for (int i = 1; i < N; i++) {
            if (v[i] != v[i - 1] * a + b) {
                cout << "B";
                return 0;
            }
        }
        cout << v[N - 1] * a + b;
    }
    return 0;
}