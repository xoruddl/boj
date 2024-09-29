#include <iostream>
#include <algorithm>

using namespace std;

int arr[53];
int N;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    if (N == 1) {
        cout << arr[0] * arr[0];
        return 0;
    }

    sort(arr, arr + N);
    cout << arr[0] * arr[N - 1];
}