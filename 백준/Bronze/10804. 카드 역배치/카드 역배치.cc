#include <iostream>
#include <algorithm>

using namespace std;

int arr[21];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 1; i <= 20; i++) {
        arr[i] = i;
    }

    int a, b;
    int n = 10;
    while (n--) {
        cin >> a >> b;
        reverse(arr + a, arr + b + 1);
    }

    for (int i = 1; i <= 20; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}