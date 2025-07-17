#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ans;
vector<int> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    for (int idx = 0; idx < N; idx++) {
        int start = 0, end = N - 1;

        while (start < end) {
            int sum = v[start] + v[end];

            if (sum > v[idx]) {
                end--;
            } else if (sum < v[idx]) {
                start++;
            } else {
                if (start != idx && end != idx) {
                    ans++;
                    break;
                } else if (start == idx) {
                    start++;
                } else {
                    end--;
                }
            }
        }
    }
    cout << ans;
}