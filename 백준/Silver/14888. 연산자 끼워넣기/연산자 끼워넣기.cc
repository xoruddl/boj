#include <iostream>

using namespace std;

int N;
int op[4];
int arr[12];
int M = -2e9;
int m = 2e9;

void fc(int result, int idx) {
    if (idx == N) {
        if (result > M) {
            M = result;
        }
        if(result < m) {
            m = result;
        }
        return;
    }

    for(int i = 0; i < 4; i++) {
        if (op[i] > 0) {
            op[i]--;
            if(i == 0) {
                fc(result + arr[idx], idx + 1);
            }
            else if(i == 1) {
                fc(result - arr[idx], idx + 1);
            }
            else if(i == 2) {
                fc(result * arr[idx], idx + 1);
            }
            else {
                fc(result / arr[idx], idx + 1);
            }
            op[i]++;
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }
    fc(arr[0], 1);
    cout << M << '\n' << m << '\n';
    return 0;
}