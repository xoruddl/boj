#include <iostream>

using namespace std;

int n, x;
int arr[100001];
int b[2000001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= x) continue;
        if (b[x - arr[i]] == 0) {
            b[arr[i]]++;
        } else {
            ans++;
        }
    }
    cout << ans;
    return 0;
}