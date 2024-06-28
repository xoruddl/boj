#include <iostream>
#include <algorithm>

using namespace std;

int Asize;  // 수열 크기
int A[1001];    // 수열
int len_dp[1001];   // 가장 긴 수열의 길이 디피
int ans[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> Asize;
    for (int i = 0; i < Asize; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < Asize; i++) {
        len_dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                len_dp[i] = max(len_dp[i], len_dp[j] + 1);
            }
        }
    }

    int maxlen = 0, maxidx;
    for (int i = 0; i < Asize; i++) {
        if (len_dp[i] > maxlen) {
            maxlen = len_dp[i];
            maxidx = i;
        }
    }

    ans[0] = A[maxidx];
    int l = maxlen - 1;
    for (int i = maxidx - 1, j = 0; i >= 0; i--) {
        if (len_dp[i] == l && A[i] < ans[j]) {
            ans[++j] = A[i];
            l--;
        }
    }
    cout << maxlen << '\n';
    for (int i = maxlen - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    return 0;
}