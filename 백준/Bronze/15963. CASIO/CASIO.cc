#include <iostream>

using namespace std;

string N, M;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    if (N == M) {
        cout << 1;
    }
    else {
        cout << 0;
    }
}
