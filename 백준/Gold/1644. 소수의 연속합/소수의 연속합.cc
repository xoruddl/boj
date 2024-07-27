#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> prime;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    vector<bool> v(N + 1, 1);

    // 소수 처리
    for (int i = 2; i * i <= N; ++i) {
        if (v[i] == 0) continue;
        for (int j = i + i; j <= N; j += i) {
            v[j] = 0;
        }
    }
    for (int i = 2; i <= N; ++i) {
        if (v[i]) prime.push_back(i);
    }

    int left = 0, right = 0;
    int sum = 0;
    int ans = 0;
    while (1) {
        if (sum > N) {
            sum -= prime[left];
            left++;
        } else if (sum < N) {
            if (right >= prime.size()) break;
            sum += prime[right];
            right++;
        } else {
            ans++;
            if (right >= prime.size()) break;
            sum += prime[right];
            right++;
        }
    }
    cout << ans;
    return 0;
}