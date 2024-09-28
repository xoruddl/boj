#include <iostream>

using namespace std;

long long N, score, P;
long long arr[53];

int main() {
    cin >> N >> score >> P;
    if (N == 0) {
        cout << 1;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long long ans = 1;
    long long cnt = 0;
    for (int i = 0; i < N; i++) {
        if (score < arr[i]) {
            ans++;
        }
        else if (arr[i] == score) {
            
        }
        else {
            break;
        }
        cnt++;
    }
    if (cnt == P) {
        ans = -1;
    }
    cout << ans;
}