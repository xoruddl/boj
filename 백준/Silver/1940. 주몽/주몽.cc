#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    v.push_back(0);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int start = 1, end = N, ans = 0;

    while (start < end) {
        if (v[start] + v[end] == M) {
            ans++;
            end--;
        } else if (v[start] + v[end] < M) {
            start++;
        } else {
            end--;
        }
    }
    cout << ans;
}