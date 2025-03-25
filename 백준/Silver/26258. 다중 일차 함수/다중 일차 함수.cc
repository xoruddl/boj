#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, Q;
vector<double> v;
vector<double> X, Y;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        X.push_back(x);
        Y.push_back(y);
    }

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        double q;
        cin >> q;

        int idx = lower_bound(X.begin(), X.end(), q) - X.begin() - 1;
        if (Y[idx] == Y[idx + 1]) {
            cout << 0 << '\n';
        }
        else if (Y[idx] > Y[idx + 1]) {
            cout << -1 << '\n';
        }
        else {
            cout << 1 << '\n';
        }
//        cout << idx << '\n';
    }
}