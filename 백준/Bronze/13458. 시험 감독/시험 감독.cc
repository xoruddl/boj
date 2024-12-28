#include <iostream>
#include <vector>

using namespace std;

int N, b, c;
vector<int> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    cin >> b >> c;

    long long ans = 0;
    for (int i = 0; i < v.size(); i++) {
        int a = v[i];
        if (a <= b) {
            ans++;
            continue;
        }
        else {
            ans++;
            a -= b;
        }

//        while (a > 0) {
//            ans++;
//            a -= c;
//        }
        ans += a / c;
        if (a % c != 0) {
            ans++;
        }
    }
    cout << ans;
}