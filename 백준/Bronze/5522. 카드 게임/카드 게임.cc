#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        ans += a;
    }
    cout << ans;
}