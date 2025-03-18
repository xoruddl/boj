#include <iostream>

using namespace std;

int N;
int ans;

void fc(int a, int b, int n) {
    if (N == n) {
        ans = a;
        return;
    }
    else {
        fc(b, a + b, n + 1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    fc(1, 2, 1);
    cout << ans;
}
