#include <iostream>

using namespace std;

int a, b, v;
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a >> b >> v;

    int time = a - b;
    ans++;
    v -= a;

    int q = v / time;
    int r = v % time;
    if (r) ans++;
    ans += q;
    cout << ans;
    return 0;
}
