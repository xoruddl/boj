#include <iostream>
#include <cmath>

using namespace std;

int alpha1[26];
int alpha2[26];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string a, b;
    cin >> a >> b;

    for (int i = 0; i < a.size(); i++) {
        alpha1[a[i] - 'a']++;
    }
    for (int i = 0; i < b.size(); i++) {
        alpha2[b[i] - 'a']++;
    }
    int ans = 0;

    for (int i = 0; i < 27; i++) {
        if (alpha1[i] && alpha2[i]) {
            ans += abs(alpha1[i] - alpha2[i]);
        } else if (alpha1[i]) {
            ans += alpha1[i];
        } else if (alpha2[i]) {
            ans += alpha2[i];
        }
    }
    cout << ans;
    return 0;
}