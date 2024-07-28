#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[2001];
bool palindrom[2001][2001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N - 1; i++) {
        palindrom[i][i] = true;
        if (arr[i] == arr[i + 1]) {
            palindrom[i][i + 1] = true;
        }
    }
    palindrom[N][N] = true;

    for (int i = N - 1; i >= 1; i--) {
        for (int j = i + 2; j <= N; j++) {
            if (arr[i] == arr[j] && palindrom[i + 1][j - 1] == true) {
                palindrom[i][j] = true;
            }
        }
    }


    cin >> M;
    for (int i = 0; i < M; ++i) {
        int s, e;
        cin >> s >> e;
        cout << palindrom[s][e] << '\n';
    }
    return 0;
}