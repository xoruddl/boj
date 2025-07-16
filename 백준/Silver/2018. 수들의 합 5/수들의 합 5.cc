#include <iostream>

using namespace std;

int N;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    int ans = 1;
    int start = 1, end = 1;
    int sum = 1;

    while (end != N) {
        if (sum == N) {
            ans++;
            end++;
            sum += end;
        } else if (sum > N) {
            sum -= start;
            start++;
        } else {
            end++;
            sum += end;
        }
    }

    cout << ans;
}