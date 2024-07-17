#include <iostream>

using namespace std;

int N, A, B;
int cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> A >> B;
    while (A != B) {
        A = (A + 1) / 2;
        B = (B + 1) / 2;
        cnt++;
    }
    cout << cnt;
    return 0;
}