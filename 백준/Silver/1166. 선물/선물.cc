#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, L, W, H;

bool fc(long double mid) {
    long long a = L / mid;
    long long b = W / mid;
    long long c = H / mid;

    long long cnt = a * b * c;

    if (cnt >= N) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> L >> W >> H;

    long double left = 0;
    long double right = min(L, min(W, H));
    long double ans;

    int cnt = 0;
    while (left < right) {
        if (cnt == 150) break;

        double mid = (left + right) / 2;

        if (fc(mid)) {
            left = mid;
            ans = mid;
        }
        else {
            right = mid;
        }
        cnt++;
    }

    cout.precision(30);
    cout << ans;
    return 0;
}