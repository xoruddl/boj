#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;
vector<int> ans;

void fc(int x, int len) {
    if (len == M) {
        for (int i = 0; i < M; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }

    int last = 0;

    for (int i = x; i < N; i++) {
        if (v[i] != last) {
            ans.push_back(v[i]);
            last = ans[len];
            fc(i, len + 1);
            ans.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    fc(0, 0);

    return 0;
}