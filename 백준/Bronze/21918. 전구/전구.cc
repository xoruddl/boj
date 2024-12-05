#include <iostream>

using namespace std;

int N, M;
int light[4003];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> light[i];
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            light[b] = c;
        }
        else if (a == 2) {
            for (int j = b; j <= c; j++) {
                light[j] = light[j] ? 0 : 1;
            }
        }
        else if (a == 3) {
            for (int j = b; j <= c; j++) {
                light[j] = 0;
            }
        }
        else {
            for (int j = b; j <= c; j++) {
                light[j] = 1;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << light[i] << " ";
    }
}