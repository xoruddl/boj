#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int L, n;
bool arr[1003];
vector<int> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> L;
    for (int i = 0; i < L; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        arr[a] = true;
    }
    cin >> n;

    if (arr[n] == true) {
        cout << 0;
        return 0;
    }

    sort(v.begin(), v.end());
    int start = 0, end = 0;

    for (int i = 0; i < L; i++) {
        if (v[0] > n) {
            start = 1;
            end = v[0] - 1;
        }
        if (v[i] < n && v[i + 1] > n) {
            start = v[i] + 1;
            end = v[i + 1] - 1;
        }
    }

    int ans = 0;
    for (int i = start; i < n; i++) {
        int tmp = end - n + 1;
        ans = ans + tmp;
    }

    ans += end - n;

    cout << ans;
}