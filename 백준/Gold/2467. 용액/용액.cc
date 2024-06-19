#include <iostream>
#include <cmath>

using namespace std;

int N, resA, resB;
int arr[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int left = 0;
    int right = N - 1;

    int resLiquid = arr[left] + arr[right];
    resA = arr[left];
    resB = arr[right];

    while (left < right) {
        int tmpLiquid = arr[left] + arr[right];
        if (abs(resLiquid) > abs(tmpLiquid)) {
            resLiquid = abs(tmpLiquid);
            resA = arr[left];
            resB = arr[right];
        }
        if (tmpLiquid < 0) left++;
        else right--;
    }
    cout << resA << " " << resB << '\n';
    return 0;
}