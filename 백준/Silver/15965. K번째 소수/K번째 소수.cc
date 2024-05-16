#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int K;
bool prime[10000001];
int k = 1;
int ans = 2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;
    while (k < K) {
        if (prime[ans]) continue;

        int n = 1;
        while (ans * n <= 10000000) {
            prime[ans * n] = true;
            n++;
        }
        ans++;
        while (prime[ans]) ans++;
        k++;
    }
    cout << ans;
}