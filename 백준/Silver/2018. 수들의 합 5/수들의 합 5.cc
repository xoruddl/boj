#include <iostream>
#include <vector>

using namespace std;

int N, ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    int start = 0, end = 0;
    int sum = 0;

    while (1) {
        if (start == end) {
            sum = start;
            if (sum == N) {
                ans++;
            }
            end++;
        } else {
            sum = (start + end) * (end - start + 1) / 2;
            if (sum > N) {
                start++;
            } else if (sum < N) {
                end++;
            } else {
                ans++;
                end++;
            }
        }

        if (end > N) {
            break;
        }
    }
    cout << ans;
}