#include <iostream>

using namespace std;

int N, F;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> F;

    long long num = N / 100 * 100;
    int target = 0;
    for (int i = num; ;i++) {
        if (i % F == 0) {
            target = i % 100;
            break;
        }
    }
    if (target < 10) {
        cout << "0" << target;
    }
    else {
        cout << target;
    }
}