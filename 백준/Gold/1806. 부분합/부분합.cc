#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        v.push_back(a);
    }

    int left = 0, right = 0, sum = 0;
    int len = 1000000;
    while (right <= N) {
        if (sum >= S) {
            len = min(len, right - left);
            sum -= v[left++];
        } else {
            sum += v[right++];
        }
    }

    if (len == 1000000) {
        cout << 0;
        return 0;
    } else {
        cout << len;
        return 0;
    }
}