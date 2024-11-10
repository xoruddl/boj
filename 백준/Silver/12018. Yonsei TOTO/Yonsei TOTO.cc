#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> v;  // 각 과목별 커트라인 저장
int ans;

bool cmp(int a, int b) {
    if (a > b) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int p, l;
        cin >> p >> l;
        vector<int> mile;
        for (int j = 0; j < p; j++) {
            int a;
            cin >> a;
            mile.push_back(a);
        }
        sort(mile.begin(), mile.end(), cmp); // 한 과목의 마일리지 정렬
        if (l > mile.size()) {
            v.push_back(1);
        }
        else {
            v.push_back(mile[l - 1]);
        }
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        if (m >= v[i]) {
            ans++;
            m -= v[i];
        }
    }
    cout << ans;
}