#include <iostream>

using namespace std;

int arr[1003];

int main() {
    int a, b;
    cin >> a >> b;

    int cnt = 1;
    for (int i = 1; cnt < 1001; i++) {
        for (int j = 0; j < i; j++) {
            arr[cnt++] = i;
            if (cnt == 1001) break;
        }
    }
    int sum = 0;
    for (int i = a; i <= b; i++) {
        sum += arr[i];
    }
    cout << sum;
}