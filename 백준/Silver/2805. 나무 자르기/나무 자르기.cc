#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

bool check(int n) {
    long long sum = 0;

    for (auto a : v) {
        if (a - n > 0) {
            sum += (a - n);
        }
    }

    if (sum >= M) {
        return true;
    }
    else return false;
}

int bs() {
    int lo = 0;
    int hi = 1e9 + 1;

    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;

        if (!check(mid)) {
            hi = mid;
        }
        else {
            lo = mid;
        }
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        v.push_back(a);
    }

    cout << bs();
}