#include <iostream>
#include <algorithm>

using namespace std;

string N;
int arr[9];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N.size(); i++) {
        if (N[i] == '9') {
            N[i] = '6';
        }
        arr[N[i] - '0']++;
    }
    if (arr[6] % 2 == 1) {
        arr[6] = arr[6] / 2 + 1;
    } else {
        arr[6] = arr[6] / 2;
    }
    sort(arr, arr + 9);
    cout << arr[8];
    return 0;
}