#include <iostream>

using namespace std;

string s;
bool palin[2501][2501];
int res[2501];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;
    int N = s.size();
    s = " " + s;

    for (int i = 1; i < N; i++) {
        palin[i][i] = true;
        if (s[i] == s[i + 1]) {
            palin[i][i + 1] = true;
        }
    }
    palin[N][N] = true;

    for (int i = N - 1; i >= 1; i--) {
        for (int j = i + 2; j <= N; j++) {
            if (s[i] == s[j] && palin[i + 1][j - 1] == true) {
                palin[i][j] = true;
            }
        }
    }

    res[0] = 0;
    for (int i = 1; i <= N; i++) {
        res[i] = 987654321;
        for (int j = 1; j <= i; j++) {
            if (palin[j][i] && res[i] > res[j - 1] + 1) {
                res[i] = res[j - 1] + 1;
            }
        }
    }
    cout << res[N];
    return 0;
}